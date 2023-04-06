#
# Device Update for IoT Hub
# PowerShell module for uploading file to Azure Storage Blob Container.
# Copyright (c) Microsoft Corporation.
#

#Requires -Version 5.0
#Requires -Modules Az.Accounts, Az.Storage

function Get-AduAzBlobContainer
{
<#
    .SYNOPSIS
        Get a reference to Azure Storage Blob container object.
#>
    [CmdletBinding()]
    Param(
        # Azure subscription id.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        $SubscriptionId,

        # Azure resource group name of the Azure Storage account.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        $ResourceGroupName,

        # Azure Storage account name.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        $StorageAccountName,

        # Blob container name.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        $ContainerName,

        # Skip connecting to Azure.
        [switch] $SkipLogin
    )

    if (!$SkipLogin)
    {
        Connect-AzAccount -ErrorAction Stop -UseDeviceAuthentication | Out-Null
        $subscription = Get-AzSubscription -SubscriptionId $SubscriptionId -ErrorAction Stop
        Set-AzContext $subscription -ErrorAction Stop | Out-Null
    }

    $account = Get-AzStorageAccount -ResourceGroupName $ResourceGroupName -Name $StorageAccountName -ErrorAction Stop
    New-AzStorageContainer -Name $ContainerName -Context $account.Context -ErrorAction SilentlyContinue | Out-Null
    $container = Get-AzStorageContainer -Name $ContainerName -Context $account.Context -ErrorAction Stop
    return $container
}

function Copy-AduFileToAzBlobContainer
{
<#
    .SYNOPSIS
        Upload file to specified Azure Storage Blob container, and return its Shared-Access-Signature (SAS) URL.
#>
    [CmdletBinding()]
    Param(
        # Path to file.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        $FilePath,

        # Blob name to use.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        $BlobName,

        # Azure Storage Blob container object.
        [Parameter(Mandatory=$true)]
        [ValidateNotNull()]
        [Microsoft.WindowsAzure.Commands.Common.Storage.ResourceModel.AzureStorageContainer] $BlobContainer
    )

    $blob = Set-AzStorageBlobContent -File $FilePath -Blob $BlobName -Container $BlobContainer.Name -Context $BlobContainer.Context -Force -ErrorAction Stop
    $uri = New-AzStorageBlobSASToken -Container $BlobContainer.Name -Blob $blob.Name -Permission r `
                                     -StartTime (Get-Date).AddMinutes(-30) -ExpiryTime (Get-Date).AddHours(6) -Context $blob.Context -FullUri -ErrorAction Stop
    return $uri
}

Export-ModuleMember -Function Copy-AduFileToAzBlobContainer, Get-AduAzBlobContainer
