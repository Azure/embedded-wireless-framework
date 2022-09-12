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
5. Connect the TX pin of the Quectel BG96 board to PA23 and RX pin to PA22 on the EXT1 header(PIC32CM LS60 Curiosity Pro). Also connect the necessary power and GND cables between the boards.  Alternatively if a MIKROE BG96 click is used, plug it in the mikrobus connector on the board. In the main.c comment our mikroe_bg96_power_on() if using the click board.  Open your terminal program and connect to the serial port for looking at the output (typical settings 115200-8-N-1)
6. Run the ewf_info_baremetal_bg96 example to verify basic communication with the modem, check the output on the terminal for progress and possible errors.
7. Run the ewf_certs_basic_bm_bg96 example to provision the certificates into the modem. Verify the output on the terminal, there should be no errors.
8. Run the ewf_telemetry_bm_bg96 example to see telemetry information being sent to IoT Hub. You can view the telemetry data being posted using the Azure IoT Explorer. Once the telemetry messages are sent, the application will wait one minute listening for cloud to device messages, you can use the Azure IoT Explorer to send messages to the device. You can observe the progress of the application and C2D incoming messages in the terminal.
9. Run the ewf_test_bm_bg96 example to verify basic functionality, check the output on the terminal for progress and possible errors, not all test may pass, depending on your current configuration.

