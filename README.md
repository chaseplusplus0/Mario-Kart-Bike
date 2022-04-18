# MarioKart Bike executive summary
The MarioKart exercise bike project was an attempt to create an enjoyable and practical method of combining the benefits of aerobic exercise with the fun of playing a racing video game. The idea was to make physical activity easier and more desirable through the medium of gaming in a notably novel way. Using various external control systems attached to a standard bicycle, the goal was to turn a bike into a resistive-style exercise machine and a modified Nintendo Switch controller. The main functions desired for this system included functional steering translation, tire acceleration/RPM measurement, convenient buttons for other game functions (i.e. drifting, braking, item usage, menu navigation), and a microcontroller driven resistive element for the exercise portion. Ideally, these would all function with minimal user intervention so that the player can simply connect the controller and begin racing. The placement of the control options and various systems on the bike would be in safe, out of the way locations such that the user would not need to worry about any connections, mechanical obstacles, or malfunctions when using the bike in the standard fashion. Additionally, there was a design in place for an integrated health monitoring system to aid the user in finding out calories burned during play. The system as a whole was meant to be simple and streamlined such that almost anyone could hop on and start playing quickly.

# Current Capabilities
As of the latest contributions to the repo, the project functions minimally in all fields. Each subsystem planned in the design drafts has been implemented in some recognizable form. The capabilities of each system can be found in their individual files with much more detail.

### Controls

The control systems for steering, acceleration, drifting, and item throwing are all in place and playable. They are of high enough fidelity that consistently playing and winning competitive races is very much possible with a little practice. The connection is with the Nintendo Switch over bluetooth, and once connected the bike can be used much like a standard Pro Controller. There are rudimentary menu buttons in place on the RPi touchscreen for navigation, but their functions is not yet complete. Current menu navigation must be done via the touchscreen of the Nintendo Switch.

### Resistance

The resistance subsystem has gone through many different iterations of design and testing. The one contained within the repo governs a quick-switch relay setup that causes a very brief short in the leads of the motor, acting as a quick brake force which slows the user down. The intention was to have this trigger during certain in-game events, but due to difficulty reading game/vibration data back from the console, this is done at random intervals.

### Health Monitoring

The health system functions according to an MET equation that takes in the user's weight and the length of time activity is being performed. The user enters the information and starts a timer via an RPi touchscreen GUI and then stops the clock when the race is finished, after which they can obtain the caloric burn data.

# Arduino Files

There are two Arduino compatible programs created for the two Arduino Nanos utilized in this project. The tachometer program contains the code necessary to operate the IR object-detection unit and to calculate the RPM from said unit. The motor control program contains the code to run the relay-controlled motor resistance system.

# Joycontrol Python Program

This program is what does the actual control translation from each of the control systems on the bike. It is based on the open-source "Joycontrol" github program which can be found [here](https://github.com/mart1nro/joycontrol).

However, a specific branch was used for the applications of this project, which can be instead found [here](https://github.com/Poohl/joycontrol).

# Raspberry Pi file

# Repo Contents
This repository contains various bits of code used in the Mario Kart Bike capstone project. There are two Arduino files, one python program, and one entire RPi OS containing a working version of the python program with all dependencies included.

