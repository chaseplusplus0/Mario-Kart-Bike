# MarioKart Bike Executive Summary

The MarioKart exercise bike project was an attempt to create an enjoyable and practical method of combining the benefits of aerobic exercise with the fun of playing a racing video game. The idea was to make physical activity easier and more desirable through the medium of gaming in a notably novel way. Using various external control systems attached to a standard bicycle, the goal was to turn a bike into a resistive-style exercise machine and a modified Nintendo Switch controller. The main functions desired for this system included functional steering translation, tire acceleration/RPM measurement, convenient buttons for other game functions (i.e. drifting, braking, item usage, menu navigation), and a microcontroller driven resistive element for the exercise portion. Ideally, these would all function with minimal user intervention so that the player can simply connect the controller and begin racing. The placement of the control options and various systems on the bike would be in safe, out of the way locations such that the user would not need to worry about any connections, mechanical obstacles, or malfunctions when using the bike in the standard fashion. Additionally, there was a design in place for an integrated health monitoring system to aid the user in finding out calories burned during play. The system as a whole was meant to be simple and streamlined such that almost anyone could hop on and start playing quickly.

# Current Capabilities

As of the latest contributions to the repo, the project functions minimally in all fields. Each subsystem planned in the design drafts has been implemented in some recognizable form. The capabilities of each system can be found in their individual files with much more detail.

### Controls

The control systems for steering, acceleration, drifting, and item throwing are all in place and playable. They are of high enough fidelity that consistently playing and winning competitive races is very much possible with a little practice. The connection is with the Nintendo Switch over bluetooth, and once connected the bike can be used much like a standard Pro Controller. There are rudimentary menu buttons in place on the RPi touchscreen for navigation, but their functions is not yet complete. Current menu navigation must be done via the touchscreen of the Nintendo Switch.

### Resistance

The resistance subsystem has gone through many different iterations of design and testing. The one contained within the repo governs a quick-switch relay setup that causes a very brief short in the leads of the motor, acting as a quick brake force which slows the user down. The intention was to have this trigger during certain in-game events, but due to difficulty reading game/vibration data back from the console, this is done at random intervals.

### Health Monitoring

The health system functions according to an MET equation that takes in the user's weight and the length of time activity is being performed. The user enters the information and starts a timer via an RPi touchscreen GUI and then stops the clock when the race is finished, after which they can obtain the caloric burn data.

# Salient Outcomes

The most important outcomes of the final version of this project include the functional control scheme, the basic resistance system, and the basic health system. These systems represent the core intentions of the project itself. The control system works perfectly well to play a race in-game. Steering, acceleration, drifting, and item throwing are all present and work great, allowing for an entirely plausible simulation of a controller. The resistance system is subtle, but effective at forcing the user to pedal a bit harder in certain stages. This in addition to the base resistance introduced by connecting the motor to the flywheel driven by the bike tire creates a solid workout that isn't too difficult to play through multiple races with. Additionally, it has been noted that most people hardly notice the exercise during gameplay due to being distracted by the enjoyment of the game, only mentioning the burn afterwards. This was one of the major goals of the project in general. Lastly, the MET health system is simple to operate and informative, making the process of calorie burn estimation easy for the user to gauge if desired.

# Video Demonstration and Photo Documentation


# About us

This was a 3 person capstone project at Tennessee Technological University that took place over the course of two semesters of class. Team members include Reed Hester, Leah Faulkner, and Chase Griffin. Reed Hester is an Electrical Engineer and a graduating senior, and he worked mostly on the physical frame, modelling, and resistive element of the design. Chase Griffin is a Computer Engineer and also a graduating senior, and he worked on developing the control systems, implementing the component and sensor systems on the bike, and writing the programs to both operate and control the components and communicate with the Nintendo Switch/MarioKart game. Leah Faulkner is also a Computer Engineer, and she worked on the MET health system equations, touchscreen GUI controls, and the board box fan/airflow improvement. The supervising faculty member on this project was Jesse Roberts, and he proposed the original idea for the project itself. There was no direct customer for this project, and the intended userbase was very broad.

# Repo Contents
This repository contains various bits of code used in the Mario Kart Bike capstone project. There are two Arduino files, one python program, and one entire RPi OS containing a working version of the python program with all dependencies included.

### Arduino Files

There are two Arduino compatible programs created for the two Arduino Nanos utilized in this project. The tachometer program contains the code necessary to operate the IR object-detection unit and to calculate the RPM from said unit. The motor control program contains the code to run the relay-controlled motor resistance system.

### MET and GUI Program

There is a python program that contains the code for the GUI that operates the health system and the menu navigation buttons.

### Joycontrol Python Program

This program is what does the actual control translation from each of the control systems on the bike. It is based on the open-source "Joycontrol" github program which can be found [here](https://github.com/mart1nro/joycontrol).

However, a specific branch was used for the applications of this project, which can be instead found [here](https://github.com/Poohl/joycontrol).

### Project Reports

The reports from the project proposal and phase 1 and 2 of design are contained in this repo in pdf form to give perspective on the entire design process from start to finish. They outline each step from conceptualization of the subsystems and initial specifications to the final version of each component and sensor being used in the build. It also contains the rationale behind each design choice, why some portions were removed from the scope, and why the bike exists in the state it does currently.

### Datasheet

There is a datasheet containing the interface and control details of each subsystem and how they interact with each other. It can serve as a general outline for how to use the system itself. There is also experimental data for each system present as well.

### Design Artifacts and BOM

The 2D schematics and 3D models used in the development of this project are also included as well to give a perspective on what was involved in the design process. There is a bill of materials that also shows the cost of every relevant component and structure used.

