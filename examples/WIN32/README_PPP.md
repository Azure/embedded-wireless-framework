# The Embedded Wireless Framework (EWF) data mode example project with NetX Duo PPP on x86/WIN32  

## Overview  
In this tutorial you run Azure RTOS NetX Duo PPP working with the data mode in the modem which alows you access to full NetX activities.  

## Prerequisites  
- A PC running Microsoft Windows (Windows 10 or newer recommended)  

## Prepare the development environment  

- Toolchain: [Visual Studio](https://visualstudio.com) and cmake. You can use any edition of Visual Studio, version 2019 or newer.  

## Building the example projects  

> Note: When building the example projects, you may see build errors in the certs examples (file not found);  
> You can ignore these errors if you are not going to use these examples.  
  
## CMake (command line) and Visual Studio (Recommended)  

1. Open a terminal in the current folder. Generate the Visual Studio solution and projects files with the command,  
  
```cmake -Bbuild -A WIN32 .```  
  
2. Build the example projects from the command line (optional)  
  
```cmake --build build -j %NUMBER_OF_PROCESSORS%```  
  
3. Build/Debug/Run the example projects with Visual Studio  
  
Open the ```EWF_WIN32_Examples.sln``` solution located in the ```build``` directory with Visual Studio.  
  
## CMake projects in Visual Studio  
  
Visual Studio has native support for CMake enables you to edit, build, and debug CMake projects, more information here:  
https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170  
  
# Getting started  
Below are the projects using NetX Duo PPP.  
- **sample_ewf_netx_duo_ppp_ryz024a  
- **sample_ewf_netx_duo_ppp_exs_82_w  
- **sample_ewf_netx_duo_ppp_ryz024a  
  
Once the PPP link is established between the modem and EWF NetX Duo PPP client, the application will run basic tests
for ICMP ping, UDP echo to test server and TCP connection.

1. Acquire the necessary hardware (Cellular modem, USB-Serial adapter if required).  
2. Connect the modem to PC and find the serial port number from device manager of host PC.  
3. Edit the ewf_example.config.h to update the EWF_CONFIG_INTERFACE_WIN32_COM_PORT_FILE_NAME,  
   EWF_CONFIG_SIM_PIN and EWF_CONFIG_SIM_APN.  
4. Open the ```EWF_WIN32_Examples.sln``` solution located in the ```build``` directory with Visual Studio.  
   Ignore this step in the projects in already open in Visual Studio.  
5. You can now select the required project from Solution Explorer window, right click  
   and select "Set as startup project"
6. To run the project you can click "Local Windows Debugger" button on the toolbar or right click  
   on the project Debug->Start New Instance
   This will automatically build and run the project.
7. Once the project is running the logs like below can be seen on the windows terminal that will open.

```
[SEND][   3][AT\r]
[RECV][   6][\r\nOK\r\n]
[SEND][   3][AT\r]
[RECV][   6][\r\nOK\r\n]
[SEND][   3][AT\r]
[RECV][   6][\r\nOK\r\n]
[SEND][   5][ATE0\r]
[RECV][   6][\r\nOK\r\n]
[SEND][   3][AT\r]
[RECV][   6][\r\nOK\r\n]
[SEND][  10][AT+CMEE=1\r]
[RECV][   6][\r\nOK\r\n]
```

> _NOTE:_
>1. The UDP echo test code is disabled in the ewf_example_test_netx_duo_ppp.c file.  
    If you have a UDP echo test server update the ewf_example_test_netx_duo_udp_echo_server_ip value  
	with the address of your UDP test server and enable the UDP test in ewf_example_ppp_mode_netx_duo_test function.  
>2. Some tests might fail if there was not packet received within the expexted time frame of the test code.
>3. If the application gets terminated abruptly when the modem has entered data mode, the modem must be power reset before  
    running the application again. Alternatively you can send "+++" from any serial terminal to exit the modem from data mode  
	and rerun the application. This will be improved in the next update for EWF.  
