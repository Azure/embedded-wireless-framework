# Device Update for IoT Hub Scripts (PowerShell)

1. In PowerShell, navigate AzureDeviceUpdateScripts directory and run: Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope Process.  
2. Run the following script and follow the prompt to generate the manifest files for the dev board and the simulated leaf device.  
CreateRX65NRSKUpdate.ps1 for creating import manifest for CK-RX65N project. User can use this script to create three types of import manifest. Note: the path of firmware must include the version string. You can also type **!?** for help. 

## 1. Create import manifest for host update.
Input version and path of host firmware, then firmware **firmware_2.0.0.bin** and manifest **RENESAS.CK-RX65N.2.0.0.importmanifest.json** will be generated in **RENESAS.CK-RX65N.2.0.0** folder.
```
PS > .\CreateRX65NRSKUpdate.ps1

cmdlet CreateRX65NRSKUpdate.ps1 at command pipeline position 1
Supply values for the following parameters:
(Type !? for Help.)
Version: 2.0.0
HostPath: firmware_2.0.0.bin
```

## 2. Create import manifest for host update and leaf update
Input version, path of host firmware and path of leaf firmware, then firmware **firmware_2.0.0.bin**, **leaf_firmware_2.0.0.bin** and manifest **RENESAS.CK-RX65N.2.0.0.importmanifest.json**, **RENESAS.CK-RX65N-Leaf.2.0.0.importmanifest.json** will be generated in **RENESAS.CK-RX65N.2.0.0** folder.
```
PS > .\CreateRX65NRSKUpdate.ps1

cmdlet CreateRX65NRSKUpdate.ps1 at command pipeline position 1
Supply values for the following parameters:
(Type !? for Help.)
Version: 2.0.0
HostPath: firmware_2.0.0.bin
LeafPath: ./leaf_firmware_2.0.0.bin
```

## 3. Create import manifest for leaf update
Input version, path of leaf firmware, then firmware **leaf_firmware_2.0.0.bin** and manifest **RENESAS.CK-RX65N.2.0.0.importmanifest.json**, **RENESAS.CK-RX65N-Leaf.2.0.0.importmanifest.json** will be generated in **RENESAS.CK-RX65N.2.0.0** folder.
```
PS > .\CreateRX65NRSKUpdate.ps1

cmdlet CreateRX65NRSKUpdate.ps1 at command pipeline position 1
Supply values for the following parameters:
(Type !? for Help.)
Version: 2.0.0
HostPath:
LeafPath: ./leaf_firmware_2.0.0.bin
```