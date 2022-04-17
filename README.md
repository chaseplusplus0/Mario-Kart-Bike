# Mario-Kart-Bike
This repository contains various bits of code used in the Mario Kart Bike capstone project. There are two Arduino files, one python program, and one entire RPi OS containing a working version of the python program with all dependencies included.

# Arduino Files

There are two Arduino compatible programs created for the two Arduino Nanos utilized in this project. The tachometer program contains the code necessary to operate the IR object-detection unit and to calculate the RPM from said unit. The motor control program contains the code to run the relay-controlled motor resistance system.

# Joycontrol Python Program

This program is what does the actual control translation from each of the control systems on the bike. It is based on the open-source "Joycontrol" github program which can be found [here](https://github.com/mart1nro/joycontrol).

However, a specific branch was used for the applications of this project, which can be instead found [here](https://github.com/Poohl/joycontrol).

# Raspberry Pi file


