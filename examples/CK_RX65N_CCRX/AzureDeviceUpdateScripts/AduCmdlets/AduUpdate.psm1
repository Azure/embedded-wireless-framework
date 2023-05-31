#
# Device Update for IoT Hub
# PowerShell module for creating import manifest for Device Update for IoT Hub (ADU).
# Copyright (c) Microsoft Corporation.
#

#Requires -Version 5.0

# -------------------------------------------------
# CLASSES
# -------------------------------------------------

class UpdateId
{
    [string] $Provider
    [string] $Name
    [string] $Version

    UpdateId($provider, $name, $version)
    {
        $this.Provider = $provider
        $this.Name = $name
        $this.Version = $version
    }
}

# -------------------------------------------------
# INTERNAL METHODS
# -------------------------------------------------

function Get-UpdateId
{
    Param(
        [ValidateNotNullOrEmpty()]
        [string] $Provider = $(throw "'Provider' parameter is required."),

        [ValidateNotNullOrEmpty()]
        [string] $Name = $(throw "'Name' parameter is required."),

        [ValidateNotNullOrEmpty()]
        [version] $Version = $(throw "'Version' parameter is required.")
    )

    # Server will accept any order; preserving order for aesthetics only.
    $updateId = [ordered] @{
        'provider' = $Provider
        'name' = $Name
        'version' = "$Version"
    }

    return $updateId
}

function Get-FileMetadatas
{
    Param(
        [ValidateCount(0, 5)]
        [string[]] $FilePaths = $(throw "'FilePaths' parameter is required.")
    )

    $files = @()

    foreach ($filePath in $FilePaths)
    {
        if (!(Test-Path $filePath))
        {
            throw "$filePath could not be found."
        }

        $file = Get-Item $filePath
        $fileHashes = Get-AduFileHashes $filePath

        # Server will accept any order; preserving order for aesthetics only.
        $fileMap = [ordered] @{
            'filename' = $file.Name
            'sizeInBytes' = $file.Length
            'hashes' = $fileHashes
        }

        $files += $fileMap
    }

    return $files
}

# -------------------------------------------------
# EXPORTED METHODS
# -------------------------------------------------

function Get-AduFileHashes
{
<#
    .SYNOPSIS
        Get file hashes in a format required by ADU.

    .EXAMPLE
        PS > Get-AduFileHashes -FilePath .\payload.bin
#>
    [CmdletBinding()]
    Param(
        # Full path to the file.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $FilePath
    )

    if (!(Test-Path $filePath))
    {
        throw "$FilePath could not be found."
    }

    $FilePath = Resolve-Path $FilePath

    $fs = [System.IO.File]::OpenRead($FilePath)
    $sha256 = New-Object System.Security.Cryptography.SHA256Managed
    $bytes = $sha256.ComputeHash($fs)
    $sha256.Dispose()
    $fs.Close()
    $fileHash = [System.Convert]::ToBase64String($bytes)

    $hashes = [pscustomobject]@{
        'sha256' = $fileHash
    }

    return $hashes
}

function New-AduUpdateId
{
<#
    .SYNOPSIS
        Create a new ADU update identity.

    .EXAMPLE
        PS > New-AduUpdateId -Provider Contoso -Name Toaster -Version 1.0
#>
    [CmdletBinding()]
    Param(
        # Update provider.
        [Parameter(Mandatory=$true)]
        [ValidateLength(1, 64)]
        [ValidatePattern("^[a-zA-Z0-9.-]+$")]
        [string] $Provider,

        # Update name.
        [Parameter(Mandatory=$true)]
        [ValidateLength(1, 64)]
        [ValidatePattern("^[a-zA-Z0-9.-]+$")]
        [string] $Name,

        # Update version.
        [Parameter(Mandatory=$true)]
        [version] $Version
    )

    return [UpdateId]::New($Provider, $Name, $Version)
}

function New-AduUpdateCompatibility
{
<#
    .SYNOPSIS
        Create a new ADU update compatibility info.

    .EXAMPLE
        PS > New-AduUpdateCompatibility -Manufacturer Contoso -Model Toaster
#>
    [CmdletBinding()]
    Param(
        # Compatibility properties.
        [Parameter(ParameterSetName='CustomProperties', Mandatory=$true)]
        [hashtable] $Properties,

        # Device manufacturer.
        [Parameter(ParameterSetName='BackwardCompat', Mandatory=$true)]
        [ValidateLength(1, 64)]
        [string] $Manufacturer,

        # Device model.
        [Parameter(ParameterSetName='BackwardCompat', Mandatory=$true)]
        [ValidateLength(1, 64)]
        [string] $Model
    )

    switch ($PSCmdlet.ParameterSetName)
    {
        'CustomProperties' {
            return $Properties
        }

        'BackwardCompat' {
            return @{
                manufacturer = $Manufacturer
                model = $Model
            }
        }
    }
}

function New-AduInstallationStep
{
<#
    .SYNOPSIS
        Create a new ADU installation step.

    .EXAMPLE
        PS > New-AduInstallationStep -Handler 'microsoft/swupdate:1' -Files '.\file1.json', '.\file2.zip'
#>
    [CmdLetBinding()]
    Param(
        # Step handler type in form of "{provider}/{handlerType}:{handlerTypeVersion}".
        # This parameter is forwarded to client device during deployment.
        # For example, reference ADU agent uses the following:
        # - "microsoft/swupdate:1" for SwUpdate image-based installation step.
        # - "microsoft/apt:1" for APT package-based installation step.
        [Parameter(ParameterSetName = 'inline', Mandatory=$true)]
        [ValidateLength(1, 32)]
        [ValidatePattern("^\S+\/\S+:\d{1,5}$")]
        [string] $Handler,

        # The payload filenames used for this step.
        [Parameter(ParameterSetName = 'inline', Mandatory=$true)]
        [ValidateCount(1, 10)]
        [string[]] $Files,

        # Optional JSON object argument to step handler.
        [Parameter(ParameterSetName = 'inline')]
        [hashtable] $HandlerProperties,

        # Identity of child update to install for this step.
        [Parameter(ParameterSetName = 'reference', Mandatory=$true)]
        [UpdateId] $UpdateId,

        # Optional step description.
        [ValidateLength(0, 64)]
        [string] $Description
    )

    switch ($PsCmdlet.ParameterSetName)
    {
        'inline' {
            $step = [ordered] @{
                type = 'inline'
            }

            if ($Description.Length -gt 0)
            {
                $step.description = $Description
            }

            $step.handler = $Handler
            $step.files = $Files

            if ($HandlerProperties -ne $null)
            {
                $step.handlerProperties = $HandlerProperties
            }

            return $step
        }

        'reference' {
            $step = [ordered] @{
                type = 'reference'
            }

            if ($Description.Length -gt 0)
            {
                $step.description = $Description
            }

            $step.updateId = Get-UpdateId -Provider $UpdateId.Provider -Name $UpdateId.Name -Version $UpdateId.Version

            return $step
        }
    }
}

function New-AduImportManifest
{
<#
    .SYNOPSIS
        Create a new ADU update import manifest.

    .EXAMPLE
        PS > $updateId = New-AduUpdateId -Provider Fabrikam -Name Toaster -Version 2.0
        PS > $compatInfo1 = New-AduUpdateCompatibility -Manufacturer Fabrikam -Model Toaster
        PS > $compatInfo2 = New-AduUpdateCompatibility -Properties @{ OS = "Linux"; Manufacturer = "Fabrikam" }
        PS > $step = New-AduInstallationStep -Handler 'microsoft/swupdate:1' -Files '.\file1.json', '.\file2.zip'
        PS >
        PS > New-AduImportManifest -UpdateId $updateId -Compatibility $compatInfo1, $compatInfo2 -InstallationSteps $step
#>
    [CmdletBinding()]
    Param(
        # Update identity created using New-AduUpdateId.
        [Parameter(ParameterSetName='UpdateId', Mandatory=$true)]
        [ValidateNotNull()]
        [UpdateId] $UpdateId,

        # Update provider.
        [Parameter(ParameterSetName='BackwardCompat', Mandatory=$true)]
        [ValidateLength(1, 64)]
        [ValidatePattern("^[a-zA-Z0-9.-]+$")]
        [string] $Provider,

        # Update name.
        [Parameter(ParameterSetName='BackwardCompat', Mandatory=$true)]
        [ValidateLength(1, 64)]
        [ValidatePattern("^[a-zA-Z0-9.-]+$")]
        [string] $Name,

        # Update version.
        [Parameter(ParameterSetName='BackwardCompat', Mandatory=$true)]
        [version] $Version,

        # Optional friendly update description
        [ValidateLength(0, 512)]
        [string] $Description,

        # List of compatibility information of devices this update is compatible with, created using New-AduUpdateCompatibility.
        [Parameter(Mandatory=$true)]
        [ValidateCount(1, 10)]
        [hashtable[]] $Compatibility,

        # List of update installation steps.
        [Parameter(Mandatory=$true)]
        [ValidateCount(1, 10)]
        [System.Collections.Specialized.OrderedDictionary[]] $InstallationSteps,

        # Whether the update can be deployed on its own to a device. Must be false for a referenced update.
        [bool] $IsDeployable = $true
    )

    switch ($PSCmdlet.ParameterSetName)
    {
        'UpdateId' {
            $id = Get-UpdateId -Provider $UpdateId.Provider -Name $UpdateId.Name -Version $UpdateId.Version
        }

        'BackwardCompat' {
            $id = Get-UpdateId -Provider $Provider -Name $Name -Version $Version
        }
    }

    $fileMetadatas = @()

    foreach ($step in $InstallationSteps)
    {
        if ($step.type -eq 'inline')
        {
            for ($iFile = 0; $iFile -lt $step.files.Count; $iFile++)
            {
                $meta = Get-FileMetadatas $step.files[$iFile]

                # in case multiple steps are sharing a payload file.
                if ($fileMetadatas.filename -notcontains $meta.filename)
                {
                    $fileMetadatas += $meta
                }

                # inline step requires only payload file name, convert full path to filename.
                $step.files[$iFile] = $meta.filename
            }
        }
    }

    if ($fileMetadatas.Count -gt 10)
    {
        Write-Error 'Update cannot have more than 10 payload files.'
    }

    # Server will accept any order; preserving order for aesthetics only.
    $importManifest = [ordered] @{
        updateId = $id
    }

    if ($Description.Length -gt 0)
    {
        $importManifest.description = $Description
    }

    $importManifest.isDeployable = $IsDeployable
    $importManifest.compatibility = [array] $Compatibility
    $importManifest.instructions = [ordered] @{
        steps = [array] $InstallationSteps
    }

    if ($fileMetadatas.Length -gt 0)
    {
        $importManifest.files = [array] $fileMetadatas
    }

    $importManifest.createdDateTime = (Get-Date).ToUniversalTime().ToString('o') # ISO8601
    $importManifest.manifestVersion = '4.0'

    ConvertTo-Json -InputObject $importManifest -Depth 20
}

Export-ModuleMember -Function New-AduImportManifest, New-AduUpdateId, New-AduUpdateCompatibility, New-AduInstallationStep, Get-AduFileHashes
