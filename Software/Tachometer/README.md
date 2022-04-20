# What does it do?

The tachometer program is pretty straightforward. It basically contains a delay-style function that counts the number of times an object was detected by the component. After a certain time period (about 3 seconds), the 
RPM calculation is performed and the RPM value is sent over the serial data line. There, it is recieved by the RPi and used to determine acceleration in-game.

# Dependencies

This program was designed for the Arduino Nano and the KY-032 IR obstacle avoidance sensor. Without modifying pin choices and connections, it will only work with these components. All functions used are present within the Arduino IDE. It is programmed in C++.

# Installation

To install this program, just open the Arduino file in the IDE, connect the Arduino Nano via USB to your computer, select the right board and port settings in the IDE tools, and then flash the board with the program.

# Usage

To use, just make sure it is flashed onto the Nano and that the pin connections are all done correctly. Then, make sure the KY-032 is facing the rotating object and that the LED brightness potentiometer is tuned to the right distance needed. Also, make sure that the serial is writing only the RPM (don't print anything else and don't use println) and that it is writing at 9600 baud rate (if you change this make sure to change it in the RPi serial read as well). The serial connection can be done directly from the Nano to the RPi.

PIN CONNECTIONS (NANO to KY-032):  
5V to +  
GND to -  
PIN 2 to OUT  
OPEN on EN