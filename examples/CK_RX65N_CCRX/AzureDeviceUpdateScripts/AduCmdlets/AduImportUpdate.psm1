#
# Device Update for IoT Hub
# PowerShell module for creating and preparing update for import into Device Update for IoT Hub (ADU).
# Copyright (c) Microsoft Corporation.
#

#Requires -Version 5.0
using module .\AduUpdate.psm1 # to import classes
Import-Module $PSScriptRoot\AduAzStorageBlobHelper.psm1 -ErrorAction Stop

function New-AduImportUpdateInput
{
<#
    .SYNOPSIS
        Stage update artifacts in provided Azure Storage Blob Container and create the request body for ADU Import Update API.

    .EXAMPLE
        PS > $container = Get-AduAzBlobContainer -SubscriptionId $subscriptionId -ResourceGroupName $resourceGroupName -StorageAccountName $storageAccount -ContainerName $containerName
        PS >
        PS > $updateId = New-AduUpdateId -Provider Fabrikam -Name Toaster -Version 2.0
        PS > $compatInfo1 = New-AduUpdateCompatibility -Manufacturer Fabrikam -Model Toaster
        PS > $compatInfo2 = New-AduUpdateCompatibility -Properties @{ OS = "Linux"; Manufacturer = "Fabrikam" }
        PS > $step = New-AduInstallationStep -Handler 'microsoft/swupdate:1' -Files '.\file1.json', '.\file2.zip'
        PS >
        PS > New-AduImportUpdateInput -UpdateId $updateId -Compatibility $compatInfo1, $compatInfo2 -InstallationSteps $step -BlobContainer $container
#>
    [CmdletBinding()]
    Param(
        # Update identity created using New-AduUpdateId.
        [Parameter(Mandatory=$true)]
        [ValidateNotNull()]
        [UpdateId] $UpdateId,

        # Optional friendly update description.
        [ValidateLength(0, 512)]
        [string] $Description,

        # Whether the update can be deployed on its own to a device. Must be false for a referenced update.
        [bool] $IsDeployable = $true,

        # List of compatibility information of devices this update is compatible with, created using New-AduUpdateCompatibility.
        [Parameter(Mandatory=$true)]
        [ValidateCount(1, 10)]
        [hashtable[]] $Compatibility,

        # List of update installation steps, created using New-AduInstallationSteps
        [Parameter(Mandatory=$true)]
        [ValidateCount(1, 10)]
        [System.Collections.Specialized.OrderedDictionary[]] $InstallationSteps,

        # Azure Storage Blob container to host the files.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [Microsoft.WindowsAzure.Commands.Common.Storage.ResourceModel.AzureStorageContainer] $BlobContainer
    )

    Write-Verbose "Uploading update file(s) to Azure Blob Storage."
    $fileMetaList = @()

    $InstallationSteps | Where-Object { $_.type -eq 'inline' } | ForEach-Object {
        $_.files | ForEach-Object {
            $filename = Split-Path -Leaf (Resolve-Path $_)

            if ($fileMetaList.filename -notcontains $filename)
            {
                # Place files within updateId subdirectory in case there are filenames conflict.
                $blobName = "$updateIdStr/$filename"

                $url = Copy-AduFileToAzBlobContainer -FilePath $_ -BlobName $blobName -BlobContainer $BlobContainer -ErrorAction Stop

                $fileMeta = New-Object PSObject | Select-Object filename, url
                $fileMeta.filename = $filename
                $fileMeta.url = $url

                $fileMetaList += $fileMeta
            }
        }
    }

    Write-Verbose "Uploading import manifest to Azure Blob Storage."

    $importMan = New-AduImportManifest -UpdateId $UpdateId -Description $Description -IsDeployable $IsDeployable `
                                       -Compatibility $Compatibility -InstallationSteps $InstallationSteps `
                                       -ErrorAction Stop

    $importManJsonFile = New-TemporaryFile
    $importMan | Out-File $importManJsonFile -Encoding utf8

    Get-Content $importManJsonFile | Write-Verbose

    $importManJsonFile = Get-Item $importManJsonFile # refresh file properties
    $importManJsonHash = Get-AduFileHashes -FilePath $importManJsonFile -ErrorAction Stop
    $updateIdStr = "$($UpdateId.Provider).$($UpdateId.Name).$($UpdateId.Version)"
    $importManUrl = Copy-AduFileToAzBlobContainer -FilePath $importManJsonFile -BlobName "$updateIdStr/importmanifest.json" -BlobContainer $BlobContainer -ErrorAction Stop

    Write-Verbose "Preparing Import Update API request body."

    $importManMeta = [ordered] @{
        url = $importManUrl
        sizeInBytes = $importManJsonFile.Length
        hashes = $importManJsonHash
    }

    $importUpdateInput = [ordered] @{
        importManifest = $importManMeta
        files = $fileMetaList
    }

    Remove-Item $importManJsonFile

    return $importUpdateInput
}

Export-ModuleMember -Function New-AduImportUpdateInput, New-AduUpdateId, New-AduUpdateCompatibility, New-AduInstallationStep, Get-AduAzBlobContainer
