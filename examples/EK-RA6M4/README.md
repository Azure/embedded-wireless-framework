# Azure Small Devices Networking framework examples for Renesas RA
The purpose of these examples is to show the use of EWF with the Renesas RA family of microcontrollers.
Embedded Wireless framework(EWF) is meant to simplify connecting small devices to the internet using different connectivity adapters.
An adapter is the device or software used to connect the application using the EWF API to the internet.
An adapter can be a cellular modem, a WiFi adapter, an Ethernet adapter, a WinSock software layer, a BSD software layer or other type of device or software.
The EWF API is described in the Doxygen documentation generated out of the common code.
The source files of the EWF are located in the \src directory at the root of this repository.
The current set of examples use the EK-RA6M4 evaluation board and a ryz014 modem.


## Prerequisites

- A PC running Renesas e2studio IDE.
- If you don't have an Azure subscription, [create one for free](https://azure.microsoft.com/free/) before you begin.
- Internet connectivity for your PC.

## Prepare Azure Resources
Follow steps in [README_NETX_AZURE.md](README_NETX_AZURE.md) to create Azure resources that will be used to run the examples in the next steps of this document.

# Getting started - RYZ014
To get started with the examples, please follow these steps:
1. Acquire the necessary hardware and software: the Evaluation Kit EK-RA6M4, a Renesas RYZ014A PMOD, e2-studio with FSP 3.5 or newer, openssl, J-Link RTT viewer, Azure IoT Explorer(recommend to use v0.13.5 as latest version 0.14.x cannot show data correctly).
2. Connect to RYZ014 PMOD to EK-RA6M4 board on PMOD2 connector. Connect Micro USB cable to USB Debug pin (DEBUG 1) and another USB cable to RYZ014 micro USB pin.
3. Review and edit as necessary the files ewf.config.h and ewf_example.config.h in the different examples. Edit these files to match your configuration. Specially edit the variables EWF_CONFIG_SIM_PIN, EWF_CONFIG_IOT_HUB_HOSTNAME, EWF_CONFIG_IOT_HUB_DEVICEID.
4. Register your device with Azure IoT Hub and generate the necessary certificates and keys and corresponding header files. The detailed instructions and scripts are located in this directory \tools\cert-scripts, copy the resulting .h files into the include directory of the "certs" example
5. Start e2 studio and create a workspace in \examples\EK-RA6M4, import all the ryz014 examples into the workspace and build all examples.
6. Open J-Link RTT Viewer for viewing debug information.
7. Run the ewf_info_ryz014 example to verify basic communication with the modem, check the output on the terminal for progress and possible errors.
8. Run the ewf_test_ryz014 example to verify basic functionality, check the output on the terminal for progress and possible errors, not all test may pass, depending on your current configuration.
9. Run the ewf_certs_ryz014 example to provision the certificates into the modem. Verify the output on the terminal, there should be no errors.
10. Run the ewf_telemetry_ryz014 example to see telemetry information being sent to IoT Hub. You can view the telemetry data being posted using the Azure IoT Explorer. Once the telemetry messages are sent, the application will wait one minute listening for cloud to device messages, you can use the Azure IoT Explorer to send messages to the device. You can observe the progress of the application and C2D incoming messages in the terminal.

> _NOTE:_
>1. There is possibility of getting an error for network registration as modem may require more time for registration.  
User should increase the timeout (wait_time_seconds) in the application code. Refer to the RYZ014 system integration guide for more info.
>2. C2D message processing is not implemented in the adapter code for RYZ014 due to firmware limitation.  This will be updated in near future.

# Examples using Azure RTOS NetX Duo with EWF (offload TCP/IP driver) on RYZ014

These examples run Azure RTOS NetX Duo on top of TCP/IP stack from RYZ014 modem. Hardware setup is same as that used for "Getting Started" examples above.  
> _NOTE:_
1. The examples based on Offload TCP/IP driver have base time hardcoded (SAMPLE_SYSTEM_TIME).  These exampeles will be updated to use time from Network Synchronization using NTP servers in the future.
2. These examples require, user to wait about a minute or more depending on the time required network registration and cloud connection before performing any operations( Telemetry, Cloud to Device, Direct Method..) using Azure IOT explorer.  

- **ewf_netx_duo_azure_iot_embedded_sdk_ryz014**:  Connects an sample IoT Device that is able to send telemetry, cloud to device message.
>1.With Azure IoT Explorer, you can view the flow of telemetry from your device to the cloud. Press switch S1 or S2 and you will see message like below in the telemetry window
  
```
  2:45:23 PM, 09/26/2022:
{
  "body": {
    "Message ID": 7
  },
  "enqueuedTime": "2022-09-26T12:45:23.934Z",
  "properties": {
    "Push Button": "ON"
  }
}
```
On the RTT Viewer below output can be seen

```
00> Push Button S0 Pressed  
00> Telemetry message send: {"Message ID":7}.
```

>2. For cloud to device message, open the "Cloud-to-device message" window from the Azure IOT Explorer. In Key box type "LED" and Value box type "ON" and click "Send message to Device".  Below output is seen on RTT viewer and the Green LED on the board witll be turned ON.

```
00> Receive message from Cloud: LED = ON
00> Topic Received from Cloud ON 
00> 
00> Green LED ON
```
To turn off the LED send message with Value "OFF".

>3. Call a direct method on device
You can use Azure IoT Explorer to call a direct method that you have implemented on your device. Direct methods have a name, and can optionally have a JSON payload, configurable connection, and method timeout.  In IoT Explorer select Direct method.
Send a direct method to mimic the deive reboot. The device will recieve and output the payload as dummy data  

Method name: reboot

Payload:
{"timeout": 500}

```
00> Receive method call: reboot, with payload:{"timeout":500}
```

>4. Update device twin
  In IoT Explorer select Device twin. Modify the desired section of the Device twin, you can add a custom twin:

"weather": {
"temperature": "25"
},

and then click save. Below output will be seen on the RTT viewer terminal.
```
00> Receive desired property call: {"weather":{"temperature":"25"},"$version":2}
```

- **ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014**: Connects an IoT Plug and Play enabled device (a Thermostat) with the Digital Twin Model ID (DTMI) detailed [here](https://github.com/Azure/opendigitaltwins-dtdl/blob/master/DTDL/v2/samples/Thermostat.json) to IoT Hub, the model is a single component.
- **ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014**: Connects an IoT Plug and Play enabled device (the Temperature Controller) with the Digital Twin Model ID (DTMI) detailed [here](https://github.com/Azure/opendigitaltwins-dtdl/blob/master/DTDL/v2/samples/TemperatureController.json), the model contains multiple sub-components.

If you are running the ewf_netx_duo_azure_iot_embedded_sdk_pnp_ryz014 or ewf_netx_duo_azure_iot_embedded_sdk_pnp_temperature_controller_ryz014 examples, you can use Azure IoT Explorer to interact with IoT Plug and Play components.
Refer "Use IoT Plug and Play" section in the [README_NETX_AZURE.md](README_NETX_AZURE.md) for steps to add device model.
Wait until you see telemetry message sending logs on the RTT viewer terminal.

> _NOTE:_
Device posistioning service (ENABLE_DPS_SAMPLE) part of the examples is not tested. It will be tested and available in future updates.

