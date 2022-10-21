$gateway=Get-NetRoute -AddressFamily IPv4 | where {$_.DestinationPrefix -eq '0.0.0.0/0' -and $_.NextHop -ne '0.0.0.0'}
$gateway.NextHop
$ip=Get-NetIPConfiguration -InterfaceIndex $gateway.ifIndex
$ip.IPv4Address.IPAddress
Get-DnsClientServerAddress -InterfaceIndex $gateway.ifIndex -AddressFamily IPv4 | foreach-object {$_.ServerAddresses[0]}
gwmi -computer . -class 'win32_networkadapterconfiguration'  | Where-Object {$_.InterfaceIndex -eq $gateway.ifIndex} | foreach-object {$_.ipsubnet[0]}