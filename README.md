![Version tag](https://img.shields.io/badge/version-2.0.0-orange.svg)
# sio

# Introduction
The acronym **sio** stands for **Serial Input Output**. This library is intended for use with Arduino developement boards hosting ATMEGA microcontrollers. It provides simplifed functions for transmitting or reading serial UART data with an option to print data to a dedicated debugging monitor. 

# Index
- [Introduction](#introduction)
- [Index](#index)
- [Users Guide](#users-guide)
    - [Downloading This Library](#downloading-this-library)
    - [Examples](#examples)
- [Developers Guide](#developers-guide)
    - [Files](#files)
    - [Class Description](#class-description)

# Users Guide
## Downloading This Library
It is recommended to clone the entire repository into the  libraries folder of the installed Arduino folder  on your local machine. Use the command:
```
git clone https://github.com/arthurgomes4/sio.git
```
Ensure that the command is run from the mentioned libraries directory. 

## Examples
(to be updated soon)

# Developers Guide
## Files
A description of all files contained in this library folder.

### sio.h
This is the header file containing the class blueprints.

### sio.cpp
This file contains the source code for the function prototypes declared in the header file. 

### keywords.txt
This file is used by Arduino IDE for syntax highlighting of keywords.

### README.md
A markdown file containing the general description of the library.

## Class Description
The contents of the **sio** class are detailed and listed further in this section.

### Protected Members
- Variables
    - `bool serialMonitorStatus = false`: whether to print debugging messages to serial monitor.
    - `String serialName`: The name of the serial device connected to the ATMEGA.
    - `Stream *serialStream`: The UART serial bus over which communications which concerned device are taking place.
    - `Stream *serialMonitorStream = &Serial`: The default debugging serial connection. Usually set to **Serial**(PC with Arduino IDE serial monitor).

### Public Members
- Functions
    - `sio(void)`: empty constructor.
    - `sio(String Name, Stream *bridge)`: Constructor for initialising name of connection as well as connection bus.
    - `void setSerialMonitor(Stream *bridge = &Serial, bool Status = true)`: Used to set serial monitor status thorugh given function argument.
    - `void serialMonitor(String message)`: Prints the passed string argument to the serial monitor.
    - `void writeToSerial( String message )`: Writes given string to the serial bus of the objects device.
    - `String readFromSerial( int timeout = -1 )`: Will pause code execution for specified timeout in **milliseconds**. Returns ```'\0'``` if serial Rx buffer is still empty at the end of waiting period.
    - `String readFromSerialMonitor( int timeout = -1)`: Similar to above function, except reads only from the serial monitors Rx buffer.
    - `void toggleSerialMonitorStatus( String key )`: reads current contents of serial monitor Rx buffer. If passed string argument matches Rx buffer contents `serialMonitorStatus` is toggled.


[![Image](https://img.shields.io/badge/developed%20using-VSCode-green.svg)](https://code.visualstudio.com/)
[![Image](https://img.shields.io/badge/Developer-arthurgomes4-blue.svg)](https://github.com/arthurgomes4)

