# Connect Modem to Ubuntu WSL

## Overview
This readme will walk through the process of having USB-Serial device connected to WSL Ubuntu.

## Prerequisites

- A PC running WSL Ubuntu Linux (18.04 or above).
- Internet connectivity for your PC.

## Setup for USB conection to WSL
1. Install the latest .msi file from https://github.com/dorssel/usbipd-win/releases on the Windows PC
2. In ubuntu terminal run below commands

```
sudo apt install linux-tools-5.4.0-77-generic hwdata
sudo update-alternatives --install /usr/local/bin/usbip usbip /usr/lib/linux-tools/5.4.0-77-generic/usbip 20
```

If there are issues in above, check below link for more details to "Connect USB devices"
https://docs.microsoft.com/en-us/windows/wsl/connect-usb

## Serial Interface connection
The cellular modem is connected to PC via USB-Serial adapter.

## Steps to be followed on Host PC (Windows)
Open terminal in administrator mode and run below commands

1. Run below to list the usb devices connected to PC. This will list the devices and associated BUSID

```
  usbipd wsl list
```

2. Run below to bind the device, replace <busid> in below with the number displayed  for your usb-serial device
```
usbipd bind --force  --busid <busid>
```

3. Run below to attach the device, replace <busid> in below with the number displayed  for your usb-serial device
```
usbipd wsl attach --busid <busid>
```

At this point when you run 'usbipd wsl list' it will show your device as attached, for eg.

```
PS C:\Users\bhnaphad> usbipd wsl list
BUSID  DEVICE                                                        STATE
2-6    Surface Camera Front, Surface IR Camera Front                 Not attached
2-10   Intel(R) Wireless Bluetooth(R)                                Not attached
3-1    Lenovo USB Ethernet                                           Not attached
4-3    USB 2.0 BILLBOARD                                             Not attached
4-4    USB Serial Converter                                          Attached - Ubuntu-18.04
```
    @attention 
    > If 'usbipd wsl list' displays a warning something like below you may have issues with device connection, 
    "subipd: warning: USB filter 'XXX' is known to be incompatible with this software"
    > Run below querry on windows terminal
    reg query "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Class\{36fc9e60-c465-11cf-8056-444553540000}" /v UpperFilters
    > This will output something like "UpperFilters XXX XXX". You need to uninstall this driver or rename it in Registry
    Open regedit in Windows and rename/delete the entry for USB filter under
    "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Class\{36fc9e60-c465-11cf-8056-444553540000}

4. To remove binding and attachment to WSL run below command
```
usbipd unbind --force  --busid <busid>
usbipd wsl detach --busid <busid>
```

## Steps to be followed on WSL Ubuntu
No specific step on ubuntu for usbipd device connection. User should run the 'lsusb' or 'dmesg' or 'll /sys/class/tty/ttyUSB*'
command to find the tty to which the device was attached., for eg. in below the device is connected to ttyUSB0

```
bhupendran@MININT-VDK2EQM:/$ lsusb
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 009: ID 0403:6001 Future Technology Devices International, Ltd FT232 USB-Serial (UART) IC
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
```
```
bhupendran@MININT-VDK2EQM:/$ ll /sys/class/tty/ttyUSB*
lrwxrwxrwx 1 root root 0 Mar  2 17:47 /sys/class/tty/ttyUSB0 -> ../../devices/platform/vhci_hcd.0/usb1/1-1/1-1:1.0/ttyUSB0/tty/ttyUSB0/
```
```
bhupendran@MININT-VDK2EQM:/$ dmesg | grep tty
[26847.175332] usb 1-1: cp210x converter now attached to ttyUSB0
[26852.615723] cp210x ttyUSB0: cp210x converter now disconnected from ttyUSB0
[26880.527544] usb 1-1: FTDI USB Serial Device converter now attached to ttyUSB0
bhupendran@MININT-VDK2EQM:/$ 
```

    @attention 
    > When running the sample program that uses the serial interface, make sure to run it with sudo as serial connection will require root or sudo privileges. 

# Limitations 
During development for linux sample projects, we noticed that not all USB Serial adapter worked reliably with usbipd & WSL.
User should try devices from different manufacturers if the serial connection does not work.




