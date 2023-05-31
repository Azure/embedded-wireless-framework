#
# Device Update for IoT Hub
# Sample PowerShell script for creating a complex update with mixed installation steps.
# Copyright (c) Microsoft Corporation.
#

#Requires -Version 5.0

<#
    .SYNOPSIS
        Create a sample update with mix of inline and reference install steps. This sample update contain fake files and cannot be actually installed onto a device.

    .EXAMPLE
        PS > CreateSampleComplexUpdate.ps1 -Path ./test -UpdateVersion 1.2
#>
[CmdletBinding()]
Param(
    # Directory to create the import manifest JSON files in.
    [Parameter(Mandatory=$true)]
    [ValidateNotNullOrEmpty()]
    [string] $Path,

    # Version of update to create and import. E.g. 1.0
    [Parameter(Mandatory=$true)]
    [ValidateNotNullOrEmpty()]
    [string] $UpdateVersion
)

Import-Module $PSScriptRoot/AduUpdate.psm1 -ErrorAction Stop

# We will use arbitrary files as update payload files.
$childFile = "$env:TEMP/childFile.bin.txt"
$parentFile = "$env:TEMP/parentFile.bin.txt"
"This is a child update payload file." | Out-File $childFile -Force -Encoding utf8
"This is a parent update payload file." | Out-File $parentFile -Force -Encoding utf8

# ------------------------------
# Create a child update
# ------------------------------
Write-Host 'Preparing child update ...'

$microphoneUpdateId = New-AduUpdateId -Provider Contoso -Name Microphone -Version $UpdateVersion
$microphoneCompat = New-AduUpdateCompatibility -Manufacturer Contoso -Model Microphone
$microphoneInstallStep = New-AduInstallationStep -Handler 'microsoft/swupdate:1' -Files $childFile
$microphoneUpdate = New-AduImportManifest -UpdateId $microphoneUpdateId `
                                             -IsDeployable $false `
                                             -Compatibility $microphoneCompat `
                                             -InstallationSteps $microphoneInstallStep `
                                             -ErrorAction Stop -Verbose:$VerbosePreference

# ------------------------------
# Create another child update
# ------------------------------
Write-Host 'Preparing another child update ...'

$speakerUpdateId = New-AduUpdateId -Provider Contoso -Name Speaker -Version $UpdateVersion
$speakerCompat = New-AduUpdateCompatibility -Manufacturer Contoso -Model Speaker
$speakerInstallStep = New-AduInstallationStep -Handler 'microsoft/swupdate:1' -Files $childFile
$speakerUpdate = New-AduImportManifest -UpdateId $speakerUpdateId `
                                          -IsDeployable $false `
                                          -Compatibility $speakerCompat `
                                          -InstallationSteps $speakerInstallStep `
                                          -ErrorAction Stop -Verbose:$VerbosePreference

# ------------------------------------------------------------
# Create the parent update which parents the child update above
# ------------------------------------------------------------
Write-Host 'Preparing parent update ...'

$parentUpdateId = New-AduUpdateId -Provider Contoso -Name Toaster -Version $UpdateVersion
$parentCompat = New-AduUpdateCompatibility -Manufacturer Contoso -Model Toaster
$parentSteps = @()
$parentSteps += New-AduInstallationStep -Handler 'microsoft/script:1' -Files $parentFile -HandlerProperties @{ 'arguments'='--pre'} -Description 'Pre-install script'
$parentSteps += New-AduInstallationStep -UpdateId $microphoneUpdateId -Description 'Microphone Firmware'
$parentSteps += New-AduInstallationStep -UpdateId $speakerUpdateId -Description 'Speaker Firmware'
$parentSteps += New-AduInstallationStep -Handler 'microsoft/script:1' -Files $parentFile -HandlerProperties @{ 'arguments'='--post'} -Description 'Post-install script'

$parentUpdate = New-AduImportManifest -UpdateId $parentUpdateId `
                                      -Compatibility $parentCompat `
                                      -InstallationSteps $parentSteps `
                                      -ErrorAction Stop -Verbose:$VerbosePreference

# ------------------------------------------------------------
# Write all to files
# ------------------------------------------------------------
Write-Host 'Saving manifest and update files ...'

New-Item $Path -ItemType Directory -Force | Out-Null

$microphoneUpdate | Out-File "$Path/$($microphoneUpdateId.Provider).$($microphoneUpdateId.Name).$($microphoneUpdateId.Version).importmanifest.json" -Encoding utf8
$speakerUpdate | Out-File "$Path/$($speakerUpdateId.Provider).$($speakerUpdateId.Name).$($speakerUpdateId.Version).importmanifest.json" -Encoding utf8
$parentUpdate | Out-File "$Path/$($parentUpdateId.Provider).$($parentUpdateId.Name).$($parentUpdateId.Version).importmanifest.json" -Encoding utf8

Copy-Item $parentFile -Destination $Path -Force
Copy-Item $childFile -Destination $Path -Force

Write-Host "Import manifest JSON files saved to $Path" -ForegroundColor Green

Remove-Item $childFile -Force -ErrorAction SilentlyContinue | Out-Null
Remove-Item $parentFile -Force -ErrorAction SilentlyContinue | Out-Null
