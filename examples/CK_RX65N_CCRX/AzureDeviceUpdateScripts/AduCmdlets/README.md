# Device Update for IoT Hub - Scripts

This directory contains sample PowerShell and BASH scripts for creating import manifest and importing update to Device Update for IoT Hub.

## Creating import manifest

### Simple example

#### Using AduUpdate.psm1 (PowerShell)

The following sample command uses PowerShell module [AduUpdate.psm1](AduUpdate.psm1) to produce an import manifest for an update with single payload file to be installed by `microsoft/swupdate:1` handler:

```powershell
Import-Module ./AduUpdate.psm1
$file = './README.md'
$updateId = New-AduUpdateId -Provider Contoso -Name Toaster -Version 1.0
$compat = New-AduUpdateCompatibility -Properties @{ manufacturer = 'Contoso'; model = 'Toaster' }
$installStep = New-AduInstallationStep -Handler 'microsoft/swupdate:1'-HandlerProperties @{ installedCriteria = '1.0' } -Files $file
$update = New-AduImportManifest -UpdateId $updateId -Compatibility $compat -InstallationSteps $installStep
$update | Out-File ./contoso.toaster.1.0.importmanifest.json -Encoding utf8
```

#### Using create-adu-import-manifest.sh (BASH)

The following sample command uses BASH script [create-adu-import-manifest.sh](create-adu-import-manifest.sh) to produce an import manifest for an update with single payload file to be installed by `microsoft/swupdate:1` handler:

```bash
./create-adu-import-manifest.sh -p 'Contoso' -n 'Toaster' -v '1.0' -c 'manufacturer:Contoso' -c 'model:Toaster' -h 'microsoft/swupdate:1' -r 'installedCriteria:1.0' ./README.md > ./contoso.toaster.1.0.importmanifest.json
```

#### Sample Output

The above examples would produce the following manifest:

```json
{
  "updateId": {
    "provider": "Contoso",
    "name": "Toaster",
    "version": "1.0"
  },
  "compatibility": [
    {
      "manufacturer": "Contoso",
      "model": "Toaster"
    }
  ],
  "instructions": {
    "steps": [
      {
        "type": "inline",
        "handler": "microsoft/swupdate:1",
        "files": [
          "README.md"
        ],
        "handlerProperties": {
          "installedCriteria": "1.0"
        }
      }
    ]
  },
  "files": [
    {
      "filename": "README.md",
      "sizeInBytes": 7558,
      "hashes": {
        "sha256": "/CD7Sn6fiknWa3NgcFjGlJ+ccA81s1QAXX4oo5GHiFA="
      }
    }
  ],
  "createdDateTime": "2022-01-19T06:23:52.6996916Z",
  "manifestVersion": "4.0"
}
```

### Complex example

To create a more complex update that references one or more child updates, refer to PowerShell script [CreateSampleComplexUpdate.ps1](CreateSampleComplexUpdate.ps1) for usage. Modify the script as necessary, and run it as follow:

```powershell
./CreateSampleComplexUpdate.ps1 -Path ./exampleupdate
```

**Note**: BASH script `create-adu-import-manifest.sh` does not support creating complex update yet.

## Calling Import Update REST API

To import an update using [Import Update API](https://docs.microsoft.com/en-us/rest/api/deviceupdate/updates/import-update), import manifest JSON file and update payload files must be staged in Azure Storage Blob container, and their Shared Access Signature (SAS) URLs provided in the API request body.

PowerShell script [ImportSampleComplexUpdate.ps1](ImportSampleComplexUpdate.ps1) provides an end-to-end example of creating import manifest, uploading update files to Azure Storage Blob, and importing the update by calling `Import Update REST API`. The resulting update uses an arbitrary file as payload and cannot actually be deployed to a device.

### Prerequisites

1. Install [Azure Az PowersShell](https://docs.microsoft.com/en-us/powershell/azure/install-az-ps) module.

2. [Create an Azure Storage account](https://docs.microsoft.com/en-us/azure/storage/common/storage-account-create?tabs=azure-portal) if you do not already have one.

3. Create or get a reference to an Azure Storage Blob container. PowerShell module [AduImportUpdate.psm1](AduImportUpdate.psm1) provides a helper cmdlet for this:

    ```powershell
    Import-Module ./AduImportUpdate.psm1

    $AzureSubscriptionId = 'example'
    $AzureResourceGroupName = 'example'
    $AzureStorageAccountName = 'example'
    $AzureBlobContainerName =  'example'

    $container = Get-AduAzBlobContainer `
                    -SubscriptionId $AzureSubscriptionId `
                    -ResourceGroupName $AzureResourceGroupName `
                    -StorageAccountName $AzureStorageAccountName `
                    -ContainerName $AzureBlobContainerName
    ```

4. [Create a public Azure Active Directory (AzureAD) Client Application](https://docs.microsoft.com/en-us/azure/iot-hub-device-update/device-update-control-access#authenticate-to-device-update-rest-apis-for-publishing-and-management) if you do not already have one. This is required for  REST API authorization.

5. Obtain an OAuth authorization token for the client application. One option is to use PowerShell module [MSAL.PS](https://github.com/AzureAD/MSAL.PS):

    ```powershell
    Install-Module MSAL.PS

    $AzureAdClientId = 'example' # AzureAD application (client) ID.
    $AzureAdTenantId = 'example' # AzureAD application directory (tenant) ID.

    $token = Get-MsalToken `
                -ClientId $AzureAdClientId `
                -TenantId $AzureAdTenantId `
                -Scopes 'https://api.adu.microsoft.com/user_impersonation' `
                -Authority https://login.microsoftonline.com/$AzureAdTenantId/v2.0 `
                -Interactive `
                -DeviceCode
    ```

### Running ImportSampleComplexUpdate.ps1

```powershell
$AduAccountEndpoint = '{account}.api.adu.microsoft.com'
$AduInstanceId = '{instance}'

./ImportSampleComplexUpdate.ps1 `
    -AccountEndpoint $AduAccountEndpoint `
    -InstanceId $AduInstanceId `
    -Container $container `
    -AuthorizationToken $token `
    -Verbose
```

**Note**: An update version can only be imported once. To run the script multiple times, provide a different value for `-UpdateVersion` parameter each time.

## References

- [Import Manifest JSON Schema version 4.0](https://docs.microsoft.com/en-us/azure/iot-hub-device-update/import-schema)
- [Import concepts](https://docs.microsoft.com/en-us/azure/iot-hub-device-update/import-concepts)
