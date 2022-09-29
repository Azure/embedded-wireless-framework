# Embeed Wireless Framework examples for Renesas RX
The purpose of these examples is to show the use of EWF with the Renesas RX family of microcontrollers.
Embedded Wireless framework(EWF) is meant to simplify connecting small devices to the internet using different connectivity adapters.
An adapter is the device or software used to connect the application using the EWF API to the internet.
An adapter can be a cellular modem, a WiFi adapter, an Ethernet adapter, a WinSock software layer, a BSD software layer or other type of device or software.
The EWF API is described in the Doxygen documentation generated out of the common code.
The source files of the EWF are located in the \src directory at the root of this repository.
The current set of examples use the CK-RX65N board evaluation board and a ryz014 modem.


## Prerequisites

- A PC running Renesas e2studio IDE.
- If you don't have an Azure subscription, [create one for free](https://azure.microsoft.com/free/) before you begin.
- Internet connectivity for your PC.

## Prepare Azure Resources
Follow steps in [README_NETX_AZURE.md](README_NETX_AZURE.md) to create Azure resources that will be used to run the examples in the next steps of this document.

# Getting started - RYZ014
To get started with the examples, please follow these steps:
1. Acquire the necessary hardware and software: the Evaluation Kit CK-RX65N board, a Renesas RYZ014A PMOD, e2-studio with latest FIT modules, openssl, J-Link RTT viewer, Azure IoT Explorer(recommend to use v0.13.5 as latest version 0.14.x cannot show data correctly).
2. Connect to RYZ014 PMOD to CK-RX65N board on PMOD2 connector. Connect Host PC via USB cable to USB Debug pin (J14) and  another USB cable to USB-Serial pin (J20). Also connect micro USB cable to RYZ014 micro USB pin.
3. Review and edit as necessary the files ewf.config.h and ewf_example.config.h in the different examples. Edit these files to match your configuration. Specially edit the variables EWF_CONFIG_SIM_PIN, EWF_CONFIG_IOT_HUB_HOSTNAME, EWF_CONFIG_IOT_HUB_DEVICEID.
4. Start e2 studio and create a workspace in \examples\CK_RX65N_GCCRX cloud kit, import all the ryz014 examples into the workspace and build all examples.
5. Open Terminal at com port connection from the board and set it to 115200 8N1.
7. Run the ewf_info_tx_ryz014 example to verify basic communication with the modem, check the output on the terminal for progress and possible errors.

# Examples using Azure RTOS NetX Duo with EWF (offload TCP/IP driver) on RYZ014

These examples run Azure RTOS NetX Duo on top of TCP/IP stack from RYZ014 modem. Hardware setup is same as that used for "Getting Started" examples above.  
> _NOTE:_
1. The examples based on Offload TCP/IP driver have base time hardcoded (SAMPLE_SYSTEM_TIME).  These exampeles will be updated to use time from Network Synchronization using NTP servers in the future.
2. These examples require, user to wait about a minute or more depending on the time required network registration and cloud connection before performing any operations( Telemetry, Cloud to Device, Direct Method..) using Azure IOT explorer.  
3. **Currently all EWF NetX Duo examples for CK-RX65N board run Telemetry messaging. Other messaging features in these examples are work in progress.** 

- **ewf_netx_duo_azure_iot_embedded_sdk_ryz014**:  Connects an sample IoT Device that is able to send telemetry, cloud to device message.
>1.With Azure IoT Explorer, you can view the flow of telemetry from your device to the cloud

>2. For cloud to device message, open the "Cloud-to-device message" window from the Azure IOT Explorer. 

>3. Call a direct method on device
You can use Azure IoT Explorer to call a direct method that you have implemented on your device. Direct methods have a name, and can optionally have a JSON payload, configurable connection, and method timeout.  In IoT Explorer select Direct method.
Send a direct method to mimic the deive reboot. The device will recieve and output the payload as dummy data  

Method name: reboot

Payload:
{"timeout": 500}

>4. Update device twin
  In IoT Explorer select Device twin. Modify the desired section of the Device twin, you can add a custom twin:

"weather": {
"temperature": "25"
},

and then click save. Below output will be seen on the terminal.

- **ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014**: Connects an IoT Plug and Play enabled device (a Thermostat) with the Digital Twin Model ID (DTMI) detailed [here](https://github.com/Azure/opendigitaltwins-dtdl/blob/master/DTDL/v2/samples/Thermostat.json) to IoT Hub, the model is a single component.
- **ewf_netx_duo_azure_sdk_pnp_temp_controller_ryz014**: Connects an IoT Plug and Play enabled device (the Temperature Controller) with the Digital Twin Model ID (DTMI) detailed [here](https://github.com/Azure/opendigitaltwins-dtdl/blob/master/DTDL/v2/samples/TemperatureController.json), the model contains multiple sub-components.

If you are running the ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014 or ewf_netx_duo_azure_sdk_pnp_temp_controller_ryz014 examples, you can use Azure IoT Explorer to interact with IoT Plug and Play components.
Refer "Use IoT Plug and Play" section in the [README_NETX_AZURE.md](README_NETX_AZURE.md) for steps to add device model.
Wait until you see telemetry message sending logs on the terminal.

> _NOTE:_
Device posistioning service (ENABLE_DPS_SAMPLE) part of the examples is not tested. It will be tested and available in future updates.

