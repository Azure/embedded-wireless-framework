# Embedded Wireless Framework

The Embedded Wireless Framework simplifies the development of internet and cloud connectivity for embedded device software by providing a defined interface for wireless network adapters, host interfaces, platform adaptations, and software stack extensions through a set of APIs. The goal is to provide a standard framework for writing applications and controlling wireless network adapters (cellular, wifi, ...) while abstracting a driver interface for hardware vendors to plug in modules with self-developed drivers.

## Objectives

- Simplify development of IoT devices connecting to the cloud via various combinations of communication adapters and host processors.
- Provide lifecycle management of communication adapter drivers for embedded application code in embedded IoT devices.
- Enable wireless chip and module vendors to deliver Azure RTOS drivers for their products.
- Ease migration between communication adapters during production or product transition.
- Encapsulate common functions in a robust re-useable module while flexibly offering an interface for vendor-specific enhancements reducing development time for device builders.
- Encapsulate the port connection for cellular modules enabling agility for embedded processor vendors and device builders for various port configurations.

# Architecture

**Network Adapter** (ewf_adapter in the code) is the component that enables communication with the network by controlling and sending data through the network adapter module. The initial design is focused on cellular and wifi, but it is generic to allow for others (Ethernet, LoRa, ...). The framework defines several APIs common across adapters that can be used by applications, allowing easy access to the functionality of different adapters from common code.

**Host Interface** (ewf_interface in the code) is an abstraction for connecting the Network Adapter driver with the Network adapter. The Host interface can be replaced and the same Network Adapter driver can be used in a different scenario. For example, a cellular modem connected to the microcontroller over UART, GPIO or USB, can use the same Network adapter driver.  The Embedded Wireless Framework is abstracted from the host operating platform software allowing it to run on a variety of platforms. These can be bare-metal, RTOS or OS. Initial support is provided for Azure RTOS, FreeRTOS, bare-metal, and Windows.

<p align="center">
<a href="README_Architecture_Framework.jpg"><img src="README_Architecture_Framework.jpg" alt="Architecture" width="75%"/></a>
</p>

## Framework use

The framework API can be used directly by the application code, or another software stack. Implementations for using Azure RTOS NetX-Duo and the Azure Embedded C SDK are provided.<br/>
Application code can use the API directly, with help from the Azure Embedded C SDK, or with a software MQTT client (e.g. PAHO)
<p align="center">
<a href="README_Architecture_Application.jpg"><img src="README_Architecture_Application.jpg" alt="Architecture" width="75%"/></a>
</p>
The framework simplifies and unifies the writing of Azure RTOS NetX-Duo drivers. Drivers based on the framework can be used in parallel to classic NetX-Duo drivers; existing NetX-Duo drivers remain unmodified and supported.

<p align="center">
<a href="README_Architecture_NetX.jpg"><img src="README_Architecture_NetX.jpg" alt="Architecture" width="75%"/></a>
</p>
For details on the framework API look at the doxygen generated documentation.

# Build and Test

The code is built out of each individual example. Refer to each example for more details. Note: The examples are built using different tool-chains and IDEs.

# Examples and drivers

This is the list of supported network adapters, host interfaces, software platforms and hardware boards currently supported or under development.

# Network Adapters

The framework supports several network adapter types.

## Cellular
Cellular modems in the same family are likely to work with small changes:
- Quectel BG96
- Quectel BG95
- Quectel BC95
- Renesas RYZ014
- SIMCom SIM7000
- SIMCom SIM7600
- SIMCom SIM900
- SIMCom SIM868
- SIMCom SIM800

## WiFi
- ESP8266
- ESP8285
- ESP-WROOM-02
- MX-CHIP EMW3080

## LoRa
- LoRa E5
- EBYTE E32
- SEMTECH SX1276

## Ethernet
- WIZnet W5500
- WIZnet W5100

# Host Interfaces

These interfaces can be used in any combination with the supported adapters:
- WIN32 COM (adapter built-in USB, or over FTDI FT232RL, CP2102, CH314T, ...)
- Linux serial port (adapter built-in USB, or over FTDI FT232RL, CP2102, CH314T, ...)
- ST STM32xxxx UART
- Renesas RAxxxx UART
- Renesas RXxxxx UART
- NXP LPCxxxx UART
- Microchip/Atmel SAMxxxx UART
- Generic GPIO bit-banging
- Azure RTOS USBX CDC ACM

# Software platforms

- Azure RTOS (on embedded boards and Windows/Linux emulation)
- FreeRTOS (on embedded boards and Windows/Linux emulation)
- WIN32
- bare-metal

# Hardware boards

- Windows on PC
- Linux on PC and on Raspberry Pi
- ST STM32U585 Discovery Kit for IoT
- ST STM32L496 Discovery Kit
- ST STM32L475 Discovery Kit IoT Node
- ST STM32L7S5 Discovery Kit IoT Node
- Renesas RA EK-RA6M4
- Renesas RX RX65N Cloud Kit
- NXP LPC55S69-EVK
- Microchip SAM54-X-Plained Pro
- Raspberry Pi Pico

# Examples

These examples are currently available and actively being improved:
- Info: query adapter information, example for verifying basic operation of the framework
- Test: test adapter functionality, useful for further development and troubleshooting
- Certs/basic: provision certificates and keys into the network adapter for a single end-point
- Telemetry/basic: send telemetry messages to the Azure IoT Hub
- Paho MQTT client for embedded C
- PAHO MQTT client + Azure Embedded C SDK
- EWF + Azure RTOS NetX Duo

# Contributing

This project welcomes contributions and suggestions.  Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.opensource.microsoft.com.

When you submit a pull request, a CLA bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., status check, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

# Trademarks

This project may contain trademarks or logos for projects, products, or services. Authorized use of Microsoft
trademarks or logos is subject to and must follow
[Microsoft's Trademark & Brand Guidelines](https://www.microsoft.com/en-us/legal/intellectualproperty/trademarks/usage/general).
Use of Microsoft trademarks or logos in modified versions of this project must not cause confusion or imply Microsoft sponsorship.
Any use of third-party trademarks or logos are subject to those third-party's policies.

# Related

For more information on the software components used in this project, follow the links below:
- [Azure](https://azure.com/)
- [Azure RTOS](https://azure.com/rtos)
