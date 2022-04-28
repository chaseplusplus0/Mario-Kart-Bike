# What does it do?

This file contains the modified version of the "Joycontrol" program used in our project. It serves as the primary control signal compiler, translator, and transmitter between the external control systems and the console/game. It runs on the RPi and connects to the Nintendo Switch via bluetooth. It is meant to simulate the datastream from a standard pro controller such that the Switch recognizes it as one.

# Dependencies

There are several dependencies to get this program working properly. First of all, it is only configured to run on the RPi 3/3B+ and cannot be guaranteed to work on other RPi device (although it technically should). It is running on the Raspian (RPi OS : Rapsian GNU/Linux 11 (bullseye)) Operating System. It also requires python3 to run the program itself as that is the language used for almost all files.

**Python** : [www.python.org/downloads](www.python.org/downloads)

As far as the libraries used within the program, many of them are detailed in the original README contents below, but there are a few additional ones required for the modifications.

If you don't already have pip:

	sudo apt install python3-pip


**GPIO Zero** : [Documentation](https://gpiozero.readthedocs.io/en/stable/index.html)

In RPi terminal:
	
	sudo apt update
	sudo apt install python3-gpiozero


**ADS1015 ADC library** : [https://github.com/adafruit/Adafruit_Blinka](https://github.com/adafruit/Adafruit_Blinka)

In RPi terminal:

	sudo pip3 install Adafruit-Blinka

Libraries in code:
	
	import board
	import busio
	import adafruit_ads1x15.ads1015 as ADS
	from adafruit_ads1x15.analog_in import AnalogIn


**Pyserial** :

	python3 -m pip install pyserial






# Installation

# Usage

# Original README Contents
***

# joycontrol

Branch: master->amiibo_edits

Emulate Nintendo Switch Controllers over Bluetooth.

Tested on Raspberry 4B Raspbian, should work on 3B+ too and anything that can do the setup.

## Features
Emulation of JOYCON_R, JOYCON_L and PRO_CONTROLLER. Able to send:
- button commands
- stick state
- nfc for amiibo read & owner registration

## Installation
- Install dependencies  
  Raspbian:
```bash
sudo apt install python3-dbus libhidapi-hidraw0 libbluetooth-dev bluez
```
  Python: (a setup.py is present but not yet up to date)  
  Note that pip here _has_ to be run as root, as otherwise the packages are not available to the root user.
```bash
sudo pip3 install aioconsole hid crc8
```
 If you are unsure if the packages are properly installed, try running `sudo python3` and import each using `import package_name`.

- setup bluetooth
  - [I shouldn't have to say this, but] make sure you have a working Bluetooth adapter\
  If you are running inside a VM, the PC might but not the VM. Check for a controller using `bluetoothctl show` or `bluetoothctl list`. Also a good indicator it the actual os reporting to not have bluetooth anymore.
  - disable SDP [only necessary when pairing]\
  change the `ExecStart` parameter in `/lib/systemd/system/bluetooth.service` to `ExecStart=/usr/lib/bluetooth/bluetoothd -C -P sap,input,avrcp`.\
  This is to remove the additional reported features as the switch only looks for a controller.\
  This also breaks all other Bluetooth gadgets, as this also disabled the needed drivers.
  - disable input plugin [experimental alternative to above when not pairing]\
  When not pairing, you can get away with only disabling the `input` plugin, only breaking bluetooth-input devices on your PC. Do so by changing `ExecStart` to `ExecStart=/usr/lib/bluetooth/bluetoothd -C -P input` instead.
  - Restart bluetooth-deamon to apply the changes:
  ```bash
    sudo systemctl daemon-reload
    sudo systemctl restart bluetooth.service
  ```
  - see [Issue #4](https://github.com/Poohl/joycontrol/issues/4) if despite that the switch doesn't connect or disconnects randomly.

## Command line interface example
There is a simple CLI (`sudo python3 run_controller_cli.py`) provided with this app. Startup-options are:
```
usage: run_controller_cli.py [-h] [-l LOG] [-d DEVICE_ID]
                             [--spi_flash SPI_FLASH] [-r RECONNECT_BT_ADDR]
                             [--nfc NFC]
                             controller

positional arguments:
  controller            JOYCON_R, JOYCON_L or PRO_CONTROLLER

optional arguments:
  -h, --help            show this help message and exit
  -l LOG, --log LOG     BT-communication logfile output
  -d DEVICE_ID, --device_id DEVICE_ID
                        not fully working yet, the BT-adapter to use
  --spi_flash SPI_FLASH
                        controller SPI-memory dump to use
  -r RECONNECT_BT_ADDR, --reconnect_bt_addr RECONNECT_BT_ADDR
                        The Switch console Bluetooth address (or "auto" for
                        automatic detection), for reconnecting as an already
                        paired controller.
  --nfc NFC             amiibo dump placed on the controller. Equivalent to
                        the nfc command.

```

To use the script:
- start it (this is a minimal example)
```bash
sudo python3 run_controller_cli.py PRO_CONTROLLER
```
- The cli does sanity checks on startup, you might get promps telling you they failed. Check the command-line options and your setup in this case. (Note: not the logging messages). You can however still try to proceed, sometimes it works despite the warnings.

- Afterwards a PRO_CONTROLLER instance waiting for the Switch to connect is created.

- If you didn't pass the `-r` option, Open the "Change Grip/Order" menu of the Switch and wait for it to pair.

- If you already connected the emulated controller once, you can use the reconnect option of the script (`-r <Switch Bluetooth Mac address>`). Don't open the "Change Grip/Order" menu in this case, just make sure the switch is turned on. You can find out a paired mac address using the `bluetoothctl paired-devices` system command or pass `-r auto` as address for automatic detection.

- After connecting, a command line interface is opened.  
  Note: Press \<enter> if you don't see a prompt.

  Call "help" to see a list of available commands.

## API

See the `run_controller_cli.py` for an example how to use the API. A minimal example:

```python
from joycontrol.protocol import controller_protocol_factory
from joycontrol.server import create_hid_server
from joycontrol.controller import Controller

# the type of controller to create
controller = Controller.PRO_CONTROLLER # or JOYCON_L or JOYCON_R
# a callback to create the corresponding protocol once a connection is established
factory = controller_protocol_factory(controller)
# start the emulated controller
transport, protocol = await create_hid_server(factory)
# get a reference to the state beeing emulated.
controller_state = protocol.get_controller_state()
# wait for input to be accepted
await controller_state.connect()
# some sample input
controller_state.button_state.set_button('a', True)
# wait for it to be sent at least once
await controller_state.send()
```

## Issues
- Some bluetooth adapters seem to cause disconnects for reasons unknown, try to use an usb adapter or a raspi instead.
- Incompatibility with Bluetooth "input" plugin requires it to be disabled (along with the others), see [Issue #8](https://github.com/mart1nro/joycontrol/issues/8)
- The reconnect doesn't ever connect, `bluetoothctl` shows the connection constantly turning on and off. This means the switch tries initial pairing, you have to unpair the switch and try without the `-r` option again.
- ...

## Thanks
- Special thanks to https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering for reverse engineering of the joycon protocol
- Thanks to the growing number of contributers and users

## Resources

[Nintendo_Switch_Reverse_Engineering](https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering)

[console_pairing_session](https://github.com/timmeh87/switchnotes/blob/master/console_pairing_session)

[Hardware Issues thread](https://github.com/Poohl/joycontrol/issues/4)
