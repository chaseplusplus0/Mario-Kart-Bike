# What does it do?

This program generates the GUI for the MET health system and menu navigation buttons. It creates a graphical layout for the RPi touchscreen with several buttons, a keypad, and several display labels that allow the user to enter data for the caloric burn calculation as well as achieve basic menu navigation in the game during menu sequences.

# Dependencies

This program was written in Python 3 using the Tkinter toolkit to build the GUI. Tkinter is a part of the Python 3 library by default. It was written and formatted explicitly for the RPi 7" touchscreen module, but it can work without it using the desktop RPi controls.

# Installation

To install this program, simply clone the file and make sure Python 3 is installed on the computer. Additionally, if using the touchscreen, make sure the driver is up to date.

# Usage

To use, ensure the touchscreen is connected to the RPi, and then run the program. The GUI can be moved into place on the screen manually from the desktop if it does not fit. The keypad and corresponding weight and age buttons allow user data entry. The start and stop buttons control the timer. The calculation is performed on the stop of the timer. When using for a race measurement, simply enter the weight and age data, and then start the timer at the beginning of the race. When the race is over, hit stop, and your calorie burn count should be displayed. The menu buttons work like the standard d-pad and a/b buttons of a controller and can be used as such.