# Azure Small Devices Networking framework examples for NXP LPC55S69-EVK and Quectel BG96
The purpose of these examples is to show the use of EWF with the NXP LPC55S69-EVK board.
Embedded Wireless framework(EWF) is meant to simplify connecting small devices to the internet using different network adapters.
A network adapter is the device or software used to connect the application using the EWF API to the internet.
A network adapter can be a cellular modem, a WiFi adapter, an Ethernet adapter, a WinSock software layer, a BSD software layer or other type of device or software.
The EWF API is described in the Doxygen documentation generated out of the common code.
The source files of the EWF are located in the \src directory at the root of this repository.
The current set of examples use the LPC55S69-EVK evaluation board and a Quectel BG96 modem in an Arduino shield.

# Getting started
To get started with the examples, please follow these steps:
1. Acquire the necessary hardware and software: the LPC55S69-EVK, a Quectel BG96 Arduino shield, MCUXpresso IDE v11.6.0 or newer, openssl, Azure IoT Explorer and a terminal program (like TeraTerm).
2. Connect the Quectel BG96 Arduino shield to the LPC55S69-EVK board. Connect a Micro USB cable to the Debug Link connector (P6) on the LPC55S69-EVK board and the other end to your development PC.
3. Review and edit as necessary the files ewf.config.h and ewf_example.config.h in the different examples. Edit these files to match your configuration. Specially edit the variables EWF_CONFIG_SIM_PIN, EWF_CONFIG_IOT_HUB_HOSTNAME, EWF_CONFIG_IOT_HUB_DEVICEID.
4. Register your device with Azure IoT Hub and generate the necessary certificates and keys and corresponding header files. The detailed instructions and scripts are located in this directory \tools\cert-scripts, copy the resulting .h files into the sources directory of the "certs" example
5. Start MCUXpresso IDE and create a workspace in \examples\LPC55S69, import all the examples into the workspace and build all examples.
6. Open a terminal and connect it to the serial port for the LPC55S69-EVK board for viewing debug information. Typical settings are 115200-8-N-1.
7. Run the lpcxpresso55s69_ewf_info_tx_bg96 example to verify basic communication with the modem, check the output on the terminal for progress and possible errors.
8. Run the lpcxpresso55s69_ewf_test_tx_bg96 example to verify basic functionality, check the output on the terminal for progress and possible errors, not all test may pass, depending on your configuration and service.
9. Run the lpcxpresso55s69_ewf_certs_tx_bg96 example to provision the certificates into the modem. Verify the output on the terminal, there should be no errors.
10. Run the lpcxpresso55s69_ewf_telemetry_tx_bg96 example to see telemetry information being sent to IoT Hub. You can view the telemetry data being posted using the Azure IoT Explorer. The telemetry messages are sent for an hour. While the application is running it is also listening for cloud to device messages, you can use the Azure IoT Explorer to send messages to the device. You can observe the progress of the application and C2D incoming messages in the terminal.
