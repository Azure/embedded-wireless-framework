# The Embedded Wireless Framework (EWF) examples for STM32L475 discovery kit for IoT node using STM32CubeIDE
The purpose of these examples is to show the use of EWF with the STM32L4 family of microcontrollers.
EWF is meant to simplify connecting small devices to the internet using different connectivity adapters.
An adapter is the device or software used to connect the application using the EWF API to the internet.
An adapter can be a cellular modem, a WiFi adapter, an Ethernet adapter, a WinSock software layer, a BSD software layer or other type of device or software.
The EWF API is described in the Doxygen documentation generated out of the common code.
The source files of the EWF are located in the \src directory at the root of this repository.
The current set of examples use the STM32L4 discovery kit for IoT node board and a BG96 or BG95 modem on an Arduino shield board, with the TX/RX pins on D0/D1.

# Getting started
To get started with the examples, please follow these steps:
1. Acquire the necessary hardware and software: the STM32L475 discovery kit for IoT node board, a Quectel BG96 based board with RX/TX pins mapped to D0/D1, STM32CubeIDE 1.10.1 or newer, openssl, Azure IoT Explorer(recommend to use v0.13.5 as latest version 0.14.x cannot show data correctly).
2. Review and edit as necessary the files ewf.config.h and ewf_example.config.h in the different examples. Edit these files to match your configuration. Specially edit the variables EWF_CONFIG_SIM_PIN, EWF_CONFIG_IOT_HUB_HOSTNAME, EWF_CONFIG_IOT_HUB_DEVICEID.
3. Register your device with Azure IoT Hub and generate the necessary certificates and keys and corresponding header files. The detailed instructions and scripts are located in this directory \tools\cert-scripts, copy the resulting .h files into the include directory of the "certs" example
4. Start STM32CubeIDE, create a workspace on the base directory for the examples, import all examples into the workspace and build all examples.
5. Plug the Arduino shield on the board and connect the board to your computer. Open your terminal program and connect to the serial port for looking at the output (typical settings 115200-8-N-1)
1. Run the ewf_info_bg96 example to verify basic communication with the modem, check the output on the terminal for progress and possible errors.
1. Run the ewf_test_bg96 example to verify basic functionality, check the output on the terminal for progress and possible errors, not all test may pass, depending on your current configuration.
1. Run the ewf_certs_bg96 example to provision the certificates into the modem. Verify the output on the terminal, there should be no errors.
1. Run the ewf_telemetry_bg96 example to see telemetry information being sent to IoT Hub. You can view the telemetry data being posted using the Azure IoT Explorer. Once the telemetry messages are sent, the application will wait one minute listening for cloud to device messages, you can use the Azure IoT Explorer to send messages to the device. You can observe the progress of the application and C2D incoming messages in the terminal.
