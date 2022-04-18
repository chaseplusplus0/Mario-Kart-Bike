# What does it do?

The motor resistance control program is incredibly simple. It has gone through many iteration, and some skeleton code from the old systems remains in comments in case those systems are ever revisited. Currently, the operating code governs a relay connected to the leads of the DC motor. This program quickly closes and opens the relay at random time intervals (between 10 and 45 seconds). It was meant to only trigger upon recieving serial data from the RPi that contained the vibration state of the controller recieved from the game. This condition, however, turned out to be redundant because the vibration state returned was always high, meaning the trigger happened repeatedly at all times. To save serial bus space for the RPi, this condition was removed, and now the trigger happens simply randomly.

# Dependencies

This program was designed for the Arduino Nano and a relay component. Without modifying pin connections, it will only work with these components. All functions present are found within the Arduino IDE.

# Installation

To install this program, just open the Arduino file in the IDE, connect the Arduino Nano via USB to your computer, select the right board and port settings in the IDE tools, and then flash the board with the program.

# Usage

To use, make sure the program is flashed onto the Nano and that the pin connections are all done correctly. Next, make sure the relay is connected to the two motor leads such that closing it creates a short between the leads. Changing the delay between digitalwrite's can change the amount of time the leads are shorted form, however the time is currently at its minimum in the program. If using the serial line, make sure the Nano is only reading serial data, and use the read input as the condition for vibration data.

PIN CONNECTIONS (NANO to RELAY)  
5V to +  
GND to -  
PIN D6 to IN  