#
# Device Update for IoT Hub
# Sample PowerShell script for creating import manifests and payloads files for testing purposes.
# Copyright (c) Microsoft Corporation.
#

#Requires -Version 5.0

<#
    .SYNOPSIS
        Create a sample updates for testing purposes.

    .EXAMPLE
        PS > CreateCKRX65NUpdate.ps1 -Version 2.0.0 -HostPath ./firmware_2.0.0.bin `
                                                     -LeafPath ./leaf_firmware_2.0.0.bin  
#>
[CmdletBinding()]
Param(

    # Version of updateId. E.g. 2.0.0
    [Parameter(Mandatory=$true, HelpMessage = "Mandatory, the version number of updateId. E.g. 2.0.0")]
    [ValidateNotNullOrEmpty()]
    [string] $Version,

    # Path of host update firmware
    [Parameter(Mandatory=$true, HelpMessage = "Optional, the path of host update. E.g. ./firmware_2.0.0.bin")]
    [AllowEmptyString()]
    [string] $HostPath,
    
    # Path of leaf update firmware
    [Parameter(Mandatory=$true, HelpMessage = "Optional, the path of leaf update. E.g. ./leaf_firmware_2.0.0.bin")]
    [AllowEmptyString()]
    [string] $LeafPath
)

# Compatibility for host device
$DeviceManufacturer = "RENESAS"
$DeviceModel = "CK-RX65N"

# Compatibility for leaf device
$LeafDeviceManufacturer = "RENESAS"
$LeafDeviceModel = "CK-RX65N-Leaf"

# Output Manifest Path 
$OutputManifestPath = '.'

#Set the internal variables.
$UpdateVersion = $Version
$LeafUpdateVersion = $Version
$Path = $HostPath
$filename = $HostPath.split('/')[-1] -replace '.[^.]+$'
$CriteriaVersion = $filename -replace ($filename -split "\d+")[0]
$LeafPath = $LeafPath
$LeafFilename = $LeafPath.split('/')[-1] -replace '.[^.]+$'
$LeafCriteriaVersion = $LeafFilename -replace ($LeafFilename -split "\d+")[0]

if (!$Path -And !$LeafPath) {
    Write-Host "Must input at least one path!" -ForegroundColor red -BackgroundColor Black
    Exit
}

if (($Path -And !$CriteriaVersion) -Or ($LeafPath -And !$LeafCriteriaVersion)) {
    Write-Host "Can't parse version from the path!" -ForegroundColor red -BackgroundColor Black
    Exit
}

##################################################################################################
# Update 
#
# Create a update that updates 'host' and 'leaf'
#     - Parent update contains 1 inline step for host update and 1 reference step for child update
#     - Child update contains 1 inline step for leaf update.
##################################################################################################

Import-Module $PSScriptRoot/AduCmdlets/AduUpdate.psm1

$parentCompat = New-AduUpdateCompatibility -Manufacturer $DeviceManufacturer -Model $DeviceModel
$parentUpdateId = New-AduUpdateId -Provider $DeviceManufacturer -Name $DeviceModel -Version $UpdateVersion
$parentUpdateIdStr = "$($parentUpdateId.Provider).$($parentUpdateId.Name).$($parentUpdateId.Version)"

$parentFirmwareFile = $Path

Write-Host "Preparing update $parentUpdateIdStr ..."

    # -------------------------------------------------
    # Create a child update for 'leaf' component
    # -------------------------------------------------
    
    if ($LeafPath -And $LeafUpdateVersion) {

        # This component update only apply to 'leaf' compatibility.
        $childCompat = New-AduUpdateCompatibility -Manufacturer $LeafDeviceManufacturer -Model $LeafDeviceModel
        $childUpdateId = New-AduUpdateId -Provider $LeafDeviceManufacturer -Name $LeafDeviceModel -Version $LeafUpdateVersion
        $childUpdateIdStr = "$($childUpdateId.Provider).$($childUpdateId.Name).$($childUpdateId.Version)"
        $childFirmwareFile = $LeafPath

        Write-Host "Preparing child update $childUpdateIdStr ..."

        #------------
        # ADD STEP(S)
        #------------  
        
        # This update contains 1 steps.
        $childSteps = @()
        
        # Step 1 - Leaf1 update that installs leaf firmware package.
        $childSteps += New-AduInstallationStep -Handler 'microsoft/swupdate:1' `
                                               -Files $childFirmwareFile `
                                               -HandlerProperties @{ 'installedCriteria'="$LeafCriteriaVersion"} `
                                               -Description 'Leaf Firmware Update'

        # ------------------------------
        # Create child update manifest
        # ------------------------------

        Write-Host "Preparing child update manifest $childUpdateIdStr ..."

        $childManifest = New-AduImportManifest -UpdateId $childUpdateId -IsDeployable $false `
                                               -Compatibility $childCompat `
                                               -InstallationSteps $childSteps `
                                               -ErrorAction Stop

        # Create folder for manifest files and payload.
        $outputPath = "$OutputManifestPath\$parentUpdateIdStr"
        Write-Host "Saving child manifest files and payload to $outputPath..."
        New-Item $outputPath -ItemType Directory -ErrorAction SilentlyContinue | Out-Null

        # Generate manifest files.
        $childManifest | Out-File "$outputPath\$childUpdateIdStr.importmanifest.json" -Encoding utf8

        # Copy all payloads (if used)
        Copy-Item -Path $childFirmwareFile -Destination $outputPath -Force

        Write-Host " "
    }

# ----------------------------
# Create the parent update 
# ----------------------------
Write-Host "Preparing parent update $parentUpdateIdStr ..."

$parentSteps = @()

    #------------
    # ADD STEP(s)
    #------------

    if ($LeafPath -And $LeafUpdateVersion) {
        $parentSteps += New-AduInstallationStep -UpdateId $childUpdateId -Description "Leaf Firmware Update"
    }

    if ($Path -And $UpdateVersion) {
        $parentSteps += New-AduInstallationStep `
                        -Handler 'microsoft/swupdate:1' `
                        -Files $parentFirmwareFile `
                        -HandlerProperties @{ 'installedCriteria'="$CriteriaVersion"} `
                        -Description 'Host Firmware Update'
    }

# ------------------------------
# Create parent update manifest
# ------------------------------

Write-Host "Generating an import manifest $parentUpdateIdStr..."

$parentManifest = New-AduImportManifest -UpdateId $parentUpdateId `
                                        -IsDeployable $true `
                                        -Compatibility $parentCompat `
                                        -InstallationSteps $parentSteps `
                                        -ErrorAction Stop

# Create folder for manifest files and payload.
$outputPath = "$OutputManifestPath\$parentUpdateIdStr"
Write-Host "    Saving parent manifest file and payload(s) to $outputPath..."
New-Item $outputPath -ItemType Directory -ErrorAction SilentlyContinue | Out-Null

# Generate manifest file.
$parentManifest | Out-File "$outputPath\$parentUpdateIdStr.importmanifest.json" -Encoding utf8

# Copy all payloads (if used)
if ($parentFirmwareFile) { Copy-Item -Path $parentFirmwareFile -Destination $outputPath -Force }

Write-Host " "
