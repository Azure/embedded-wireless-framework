#
# Device Update for IoT Hub
# PowerShell module for calling Device Update for IoT Hub REST API (ADU).
# Copyright (c) Microsoft Corporation.
#

#Requires -Version 5.0

$API_VERSION = "api-version=2021-06-01-preview"

# --------------------------------------------------------------------------------------------------------------------------------
# INTERNAL METHODS
# --------------------------------------------------------------------------------------------------------------------------------

function Get-AuthorizationHeaders
{
    Param(
        [ValidateNotNullOrEmpty()]
        $AccessToken = $(throw "'AccessToken' parameter is required.")
    )

    return @{
        'Authorization' = "Bearer $AccessToken"
    }
}

# --------------------------------------------------------------------------------------------------------------------------------
# EXPORTED METHODS
# --------------------------------------------------------------------------------------------------------------------------------

function Start-AduImportUpdate
{
<#
    .SYNOPSIS
        Start importing an update to Device Update for IoT Hub. Method returns an operationId to be used for
        polling the operation status.

    .EXAMPLE
        PS > $updateId = New-AduUpdateId -Provider Fabrikam -Name Toaster -Version 2.0
        PS > $compatInfo = New-AduUpdateCompatibility -Manufacturer Fabrikam -Model Toaster
        PS >
        PS > $input = New-AduImportUpdateInput -UpdateId $updateId `
                                               -UpdateType microsoft/swupdate:1 -InstalledCriteria 5 `
                                               -Compatibility $compatInfo`
                                               -Files '.\file1.json', '.\file2.zip'
        PS >
        PS > Start-AduImportUpdate -AccountEndpoint sampleaccount.api.adu.microsoft.com -InstanceId sampleinstance `
                                   -AuthorizationToken 'sample token' `
                                   -ImportUpdateInput $input
#>
    [CmdletBinding()]
    Param(
        # ADU account endpoint, e.g. sampleaccount.api.adu.microsoft.com
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $AccountEndpoint,

        # ADU Instance Id.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $InstanceId,

        # Azure Active Directory OAuth Authorization Token.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $AuthorizationToken,

        # ADU Import Update API input(s).
        [Parameter(ParameterSetName="Default", Mandatory=$true)]
        [ValidateCount(1, 11)]
        [psobject[]] $ImportUpdateInput,

        # Raw API request body in JSON string format.
        [Parameter(ParameterSetName="Advanced", Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $RequestBody
    )

    $url = "https://$AccountEndpoint/deviceupdate/$InstanceId/updates?$API_VERSION&action=import"

    $headers = Get-AuthorizationHeaders -AccessToken $AuthorizationToken
    $headers.Add('Content-Type', 'application/json')

    if ($ImportUpdateInput)
    {
        $RequestBody = ConvertTo-Json -InputObject $ImportUpdateInput -Depth 50
    }

    Write-Verbose $RequestBody

    $response = Invoke-WebRequest -Uri $url -Method POST -Headers $headers -Body $RequestBody -UseBasicParsing -Verbose:$VerbosePreference

    if ($response.StatusCode -ne 202)
    {
        Write-Error $response
    }

    # .../updates/operations/86b1c73c-e041-4eea-bc7b-918248ae66da?api-version=2021-06-01-draft
    $operationId = $response.Headers["Operation-Location"].Split('/')[-1].Split('?')[0]
    return $operationId
}

function Get-AduUpdateOperation
{
<#
    .SYNOPSIS
        Get Update Operation entity.

    .EXAMPLE
        PS > Get-AduUpdateOperation -AccountEndpoint sampleaccount.api.adu.microsoft.com -InstanceId sampleinstance `
                                    -AuthorizationToken 'sample token' `
                                    -OperationId ceed45ee-3461-4ee3-b321-d3e36b6eacc7
#>
    [CmdletBinding()]
    Param(
        # ADU account endpoint, e.g. sampleaccount.api.adu.microsoft.com
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $AccountEndpoint,

        # ADU Instance Id.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $InstanceId,

        # Azure Active Directory OAuth authorization token.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $AuthorizationToken,

        # Operation identifier returned by Import/Delete Update API.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $OperationId,

        # If specified, will be populated with API response headers.
        [hashtable] $ResponseHeaders = $null
    )

    $url = "https://$AccountEndpoint/deviceupdate/$InstanceId/updates/operations/$($operationId)?$API_VERSION"
    $headers = Get-AuthorizationHeaders -AccessToken $AuthorizationToken

    $response = Invoke-WebRequest -Uri $url -Method GET -Headers $headers -UseBasicParsing -Verbose:$VerbosePreference
    $operation = $response.Content | ConvertFrom-Json

    if ($ResponseHeaders -ne $null)
    {
        $response.Headers.GetEnumerator() | ForEach-Object { $ResponseHeaders.Add($_.Key, $_.Value[0]) }
    }

    return $operation
}

function Wait-AduUpdateOperation
{
<#
    .SYNOPSIS
        Poll update operation until completion.

    .EXAMPLE
        PS > Wait-AduUpdateOperation -AccountEndpoint sampleaccount.api.adu.microsoft.com -InstanceId sampleinstance `
                                     -AuthorizationToken 'sample token' `
                                     -OperationId ceed45ee-3461-4ee3-b321-d3e36b6eacc7
#>
    [CmdletBinding()]
    Param(
        # ADU account endpoint, e.g. sampleaccount.api.adu.microsoft.com
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $AccountEndpoint,

        # ADU Instance Id.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $InstanceId,

        # Azure Active Directory OAuth authorization token.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $AuthorizationToken,

        # Operation identifier returned by Import/Delete Update API.
        [Parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $OperationId,

        # How long to wait before timing out.
        [timespan] $Timeout = (New-TimeSpan -Minutes 30)
    )

    Write-Host "Waiting for operation $operationId to complete " -NoNewline

    if ($VerbosePreference)
    {
        Write-Host '...'
    }

    $endTime = (Get-Date).Add($Timeout)

    do
    {
        $responseHeaders = @{}
        $operation = Get-AduUpdateOperation -AccountEndpoint $AccountEndpoint -InstanceId $InstanceId -AuthorizationToken $AuthorizationToken `
                                            -OperationId $operationId -ResponseHeaders $responseHeaders -ErrorAction Stop

        [int] $retryAfterInSecs = $responseHeaders["Retry-After"]

        if ($VerbosePreference)
        {
            Write-Verbose "Operation status: $($operation.Status), TraceId: $($operation.TraceId)"
        }
        else
        {
            Write-Host '.' -NoNewline
        }

        if ($operation.Status -eq 'Failed' -or $operation.Status -eq 'Succeeded')
        {
            break;
        }

        Start-Sleep -Seconds $retryAfterInSecs

    } while ((Get-Date) -lt $endTime)

    Write-Host ''

    $operation | ConvertTo-Json -Depth 20 | Out-Host

    if ($operation.Status -ne 'Succeeded')
    {
        Write-Error "Operation $Operationid had failed."
    }
    else
    {
        Write-Host "Operation $OperationId had completed successfully." -ForegroundColor Green
    }
}

Export-ModuleMember -Function Start-AduImportUpdate, Get-AduUpdateOperation, Wait-AduUpdateOperation
