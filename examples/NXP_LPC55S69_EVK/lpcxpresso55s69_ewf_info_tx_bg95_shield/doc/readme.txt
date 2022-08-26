Overview
========
The example demonstrates how to use the UART driver in Azure RTOS. For i.mx RT,
it's the LPUART driver. For LPC, it's the USART driver.

The example writes the welcome message into the default UART port. Read 4 characters
for the port, then write them back.


Toolchain supported
===================
- IAR embedded Workbench  9.20.2
- Keil MDK  5.36
- GCC ARM Embedded  10.3.1
- MCUXpresso  11.5.0

Hardware requirements
=====================
- Mini/micro USB cable
- LPCXpresso55s69 board
- Personal Computer

Board settings
==============
No special settings are required.

Prepare the Demo
================
1. Connect a micro USB cable between the PC host and the LPC-Link USB port (P6) on the board.
2. Open a serial terminal with the following settings
   - 115200 baud rate
   - 8 data bits
   - No parity
   - One stop bit
   - No flow control
3. Download the program to the target board.
4. Either press the reset button on your board or launch the debugger in your IDE to
   begin running the demo.

Running the demo
================
The welcome message will be printed out on the console:

Start the UART example...
Please input 4 characters:

Please input 4 characters, then they will be printed out.

