# The Embedded Wireless Framework (EWF) examples for PIC32CM LS60 Curiosity Pro Evaluation Kit using MPLAB
The purpose of these examples is to show the use of EWF with the PIC32 family of microcontrollers.
EWF is meant to simplify connecting small devices to the internet using different connectivity adapters.
An adapter is the device or software used to connect the application using the EWF API to the internet.
An adapter can be a cellular modem, a WiFi adapter, an Ethernet adapter, a WinSock software layer, a BSD software layer or other type of device or software.
The EWF API is described in the Doxygen documentation generated out of the common code.
The source files of the EWF are located in the \src directory at the root of this repository.
The current set of examples use the PIC32CM LS60 Curiosity Pro evaluation kit and a BG96 modem.

# Getting started
To get started with the examples, please follow these steps:
1. Acquire the necessary hardware and software: the  PIC32CM LS60 Curiosity Pro evaluation kit, a Quectel BG96 based board with RX/TX pins, MPLAB 6.0 or newer, openssl, Azure IoT Explorer(recommend to use v0.13.5 as latest version 0.14.x cannot show data correctly).
2. Review and edit as necessary the files ewf.config.h and ewf_example.config.h in the different examples. Edit these files to match your configuration. Specially edit the variables EWF_CONFIG_SIM_PIN, EWF_CONFIG_IOT_HUB_HOSTNAME, EWF_CONFIG_IOT_HUB_DEVICEID.
3. Register your device with Azure IoT Hub and generate the necessary certificates and keys and corresponding header files. The detailed instructions and scripts are located in this directory \tools\cert-scripts, copy the resulting .h files into the "NonSecure\firmware\src" directory of the "certs" example
4. Start MPLAB, import the projects
5. Connect the TX pin of the Quectel BG96 board to PA23 and RX pin to PA22 on the EXT1 header(PIC32CM LS60 Curiosity Pro). Also connect the necessary power and GND cables between the boards.  Alternatively if a MIKROE BG96 click is used, plug it in the mikrobus connector on the board. In the main.c uncomment themikroe_bg96_power_toggle() if using the click board. 

>Note: This function toggles the modem power on and off. Rerunning the application will turn off the modem. This will be updated in future.

Open your terminal program and connect to the serial port for looking at the output (typical settings 115200-8-N-1)
6. Run the ewf_info_baremetal_bg96 example to verify basic communication with the modem, check the output on the terminal for progress and possible errors.
7. Run the ewf_certs_basic_bm_bg96 example to provision the certificates into the modem. Verify the output on the terminal, there should be no errors.
8. Run the ewf_telemetry_bm_bg96 example to see telemetry information being sent to IoT Hub. You can view the telemetry data being posted using the Azure IoT Explorer. Once the telemetry messages are sent, the application will wait one minute listening for cloud to device messages, you can use the Azure IoT Explorer to send messages to the device. You can observe the progress of the application and C2D incoming messages in the terminal.
9. Run the ewf_test_bm_bg96 example to verify basic functionality, check the output on the terminal for progress and possible errors, not all test may pass, depending on your current configuration.

# Example to connect to Azure IoT Central
- **ewf_iot_central_bg96** Connects the device to IoT Central application and then sends telemetry data to the central application. User can send commands for device property from the Azure IoT Central application to the device.

> **IMPORTANT** : The mikroe_bg96_power_toggle() in the main.c will toggle the power status of the modem to ON/OFF.  
> Once the modem is powered ON, uncomment this function call when re-running the demo. 
> This will be improved in future updates.  

1. Follow steps in [README-IoT-Central](../../tools/iot-central-scripts/README.md) to create Azure IoT Central application and generate certificates.  
2. Once certifcates are created, upload them to the device in the IoT Central as mentioned in the corresponding readme document above.  Copy the .h files to the "NonSecure\firmware\src" directory of the **ewf_certs_basic_bm_bg96** project and run the example.  
This program will provision the certificates on the BG96 modem.  
3. Update the EWF_CONFIG_ID_SCOPE, EWF_CONFIG_REGISTRATION_ID value in ewf_example.config.h file in the **ewf_iot_central_bg96** project.  
4. Then run the **ewf_iot_central_bg96** project to connect to IoT Central.  
5. Build and run the application. Verify the device provisions successfully.  
Verify that telemetry appears on the device view in your IoT Central application:  
6. Open the device you created and select the command tab. "Thermostat / Get Max-Min report" will be displayed.  
Set any date and time in the "Since" option and click Run. There will be output similar to below in the Serial Terminal window.  
```
[URC^][ 100][\r\n\r\n+QMTRECV: 0,0,"$iothub/methods/POST/getMaxMinReport/?$rid=2",26,""2022-10-27T22:00:00.000Z""\r\n\r\n]
[URCv][ 100][\r\n\r\n+QMTRECV: 0,0,"$iothub/methods/POST/getMaxMinReport/?$rid=2",26,""2022-10-27T22:00:00.000Z""\r\n\r\n]
[MQTT-Basic][Message callback:][$iothub/methods/POST/getMaxMinReport/?$rid=2]["2022-10-27T22:00:00.000Z"]
[RECV][   4][\r\n> ]
[SEND][  18][{"temperature":22}]
[RECV][   6][\r\nOK\r\n]
[URC^][   2][\r\n]
[URCv][   2][\r\n]
[URC^][  16][+QMTPUB: 0,0,0\r\n]
[URCv][  16][+QMTPUB: 0,0,0\r\n]
[INFO][QUECTEL MQTT PUB]
Waiting for command request or device property message.
Client received a valid topic.
Topic: $iothub/methods/POST/getMaxMinReport/?$rid=2
Payload: "2022-10-27T22:00:00.000Z"
Start time: 2022-10-27T22:00:00.000Z
End time: 1987-01-06T12:43:36Z
Client invoked command 'getMaxMinReport'.
[SEND][  19][AT+QMTPUB=0,0,0,0,"]
[SEND][  31][$iothub/methods/res/200/?$rid=2]
[SEND][   2][",]
[SEND][   3][112]
[SEND][   1][\r]
[RECV][   4][\r\n> ]
[SEND][ 112][{"maxTemp":22,"minTemp":22,"avgTemp":22,"startTime":"2022-10-27T22:00:00.000Z","endTime":"1987-01-06T12:43:36Z"}]
[RECV][   6][\r\nOK\r\n]
[URC^][   2][\r\n]
[URCv][   2][\r\n]
[URC^][  16][+QMTPUB: 0,0,0\r\n]
[URCv][  16][+QMTPUB: 0,0,0\r\n]
[INFO][QUECTEL MQTT PUB]
Client published the Command response.
Status: 200
Payload: {"maxTemp":22,"minTemp":22,"avgTemp":22,"startTime":"2022-10-27T22:00:00.000Z","endTime":"1987-01-06T12:43:36Z"}
```
  
7. This application has two writable properties defined "targetTemperature" and "LED0".  
To view existing properties on the device, navigate to the device in the Devices section, select Manage device, and then Device Properties.  
You can update the writable properties in this view. Type below message in the right window and click "Send to device".  
  
{ "targetTemperature": 67 }  
  
On the serial terminal there will be output like below. You can see temperature value is now set to 32. The same updates will be seen in the Telemetry data on the IoT Central Application.  
  
```
v][  16][+QMTPUB: 0,0,0\r\n]
[INFO][QUECTEL MQTT PUB]
[SEND][  19][AT+QMTPUB=0,0,0,0,"]
[SEND][  38][devices/bhnaphad-dev2/messages/events/]
[SEND][   2][",]
[SEND][   2][18]
[SEND][   1][\r]
[URC^][ 116][\r\n\r\n+QMTRECV: 0,0,"$iothub/twin/PATCH/properties/desired/?$version=3",37,"{"targetTemperature":32,"$version":3}"\r\n\r\n]
[URCv][ 116][\r\n\r\n+QMTRECV: 0,0,"$iothub/twin/PATCH/properties/desired/?$version=3",37,"{"targetTemperature":32,"$version":3}"\r\n\r\n]
[MQTT-Basic][Message callback:][$iothub/twin/PATCH/properties/desired/?$version=3][{"targetTemperature":32,"$version":3}]
[RECV][   4][\r\n> ]
[SEND][  18][{"temperature":22}]
[RECV][   6][\r\nOK\r\n]
[URC^][   2][\r\n]
[URCv][   2][\r\n]
[URC^][  16][+QMTPUB: 0,0,0\r\n]
[URCv][  16][+QMTPUB: 0,0,0\r\n]
[INFO][QUECTEL MQTT PUB]
Waiting for command request or device property message.
Client received a valid topic.
Topic: $iothub/twin/PATCH/properties/desired/?$version=3
Payload: {"targetTemperature":32,"$version":3}
Status: 200
Message Type: Desired Properties
Client updated desired temperature variables locally.
Current Temperature: 32.000000
Maximum Temperature: 32.000000
Minimum Temperature: 22.000000
Average Temperature: 27.000000
[SEND][  19][AT+QMTPUB=0,0,0,0,"]
[SEND][  46][$iothub/twin/PATCH/properties/reported/?$rid=5]
[SEND][   2][",]
[SEND][   2][65]
[SEND][   1][\r]
[RECV][   4][\r\n> ]
[SEND][  65][{"targetTemperature":{"ac":200,"av":3,"ad":"success","value":32}}]
[RECV][   6][\r\nOK\r\n]
[URC^][   2][\r\n]
[URCv][   2][\r\n]
[URC^][  16][+QMTPUB: 0,0,0\r\n]
[URCv][  16][+QMTPUB: 0,0,0\r\n]
[INFO][QUECTEL MQTT PUB]
[SEND][  19][AT+QMTPUB=0,0,0,0,"]
[SEND][  46][$iothub/twin/PATCH/properties/reported/?$rid=6]
[SEND][   2][",]
[SEND][   2][29]
[SEND][   1][\r]
[RECV][   4][\r\n> ]
[SEND][  29][{"maxTempSinceLastReboot":32}]
[RECV][   6][\r\nOK\r\n]
[URC^][   2][\r\n]
[URCv][   2][\r\n]
[URC^][  16][+QMTPUB: 0,0,0\r\n]
[URCv][  16][+QMTPUB: 0,0,0\r\n]
[INFO][QUECTEL MQTT PUB]
[SEND][  19][AT+QMTPUB=0,0,0,0,"]
[SEND][  38][devices/bhnaphad-dev2/messages/events/]
[SEND][   2][",]
[SEND][   2][18]
[SEND][   1][\r]
[RECV][   4][\r\n> ]
[SEND][  18][{"temperature":32}]
[RECV][   6][\r\nOK\r\n]
[URC^][   2][\r\n]
[URCv][   2][\r\n]
````

8.  Lets try another writable device property configured in the template. Type below message click "Send to device". 
  
{ "LED0": 1 }
  

Below output will be seen on the serial terminal and the LED0 on the board will turn on.

```
FO][QUECTEL MQTT PUB]
[SEND][  19][AT+QMTPUB=0,0,0,0,"]
[SEND][  38][devices/bhnaphad-dev2/messages/events/]
[SEND][   2][",]
[SEND][   2][18]
[SEND][   1][\r]
[URC^][ 102][\r\n\r\n+QMTRECV: 0,0,"$iothub/twin/PATCH/properties/desired/?$version=5",23,"{"LED0":1,"$version":5}"\r\n\r\n]
[URCv][ 102][\r\n\r\n+QMTRECV: 0,0,"$iothub/twin/PATCH/properties/desired/?$version=5",23,"{"LED0":1,"$version":5}"\r\n\r\n]
[MQTT-Basic][Message callback:][$iothub/twin/PATCH/properties/desired/?$version=5][{"LED0":1,"$version":5}]
[RECV][   4][\r\n> ]
[SEND][  18][{"temperature":35}]
[RECV][   6][\r\nOK\r\n]
[URC^][   2][\r\n]
[URCv][   2][\r\n]
[URC^][  16][+QMTPUB: 0,0,0\r\n]
[URCv][  16][+QMTPUB: 0,0,0\r\n]
[INFO][QUECTEL MQTT PUB]
Waiting for command request or device property message.
Client received a valid topic.
Topic: $iothub/twin/PATCH/properties/desired/?$version=5
Payload: {"LED0":1,"$version":5}
Status: 200
Message Type: Desired Properties
[SEND][  19][AT+QMTPUB=0,0,0,0,"]
[SEND][  46][$iothub/twin/PATCH/properties/reported/?$rid=9]
[SEND][   2][",]
[SEND][   2][53]
[SEND][   1][\r]
[RECV][   4][\r\n> ]
[SEND][  53][{"LED0":{"ac":200,"av":5,"ad":"success","value":0.1}}]
[RECV][   6][\r\nOK\r\n]
[URC^][   2][\r\n]
[URCv][   2][\r\n]
[URC^][  16][+QMTPUB: 0,0,0\r\n]
[URCv][  16][+QMTPUB: 0,0,0\r\n]
[INFO][QUECTEL MQTT PUB]
```
  
To turn off the LED0, send  
{ "LED0": 0 }  
  