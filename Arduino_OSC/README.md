# NIME 2022

## Arduino OSC

- Register your Arduino Nano 33 IoT to use the secure Sandbox370 network
  - Upload [MACaddress sketch](https://github.com/yonatanrozin/nime2022/tree/main/Arduino_OSC/MACaddress) to Arduino
  - Copy MAC address (XX:XX:XX:XX:XX:XX) from Serial Monitor
  - Register your device [here](https://computer.registration.nyu.edu/) using MAC address
  - Description can be anything, DeviceType = "other"
- Arduino WiFiOSC ([starter sketch](https://github.com/yonatanrozin/nime2022/tree/main/Arduino_OSC/arduino_OSC_starter))
  - Enter your computer's IP address separated by commas and port # (or keep 8888)
  - Create OSCMessage object with OSC address ("/anything")
  - Add 1 (or more) data points to the message
  - Create UDP packet and send OSC message
  - Repeat
- OSC to Ableton
  - Install [Ableton Connection Kit](https://www.ableton.com/en/packs/connection-kit/) (if not already installed)
  - Packs -> Connection Kit -> Devices -> OSC TouchOSC
  - Select IP port you chose in the Arduino code
  - Click "learn" to listen for incoming OSC messages, then map the value to an Ableton knob, slider, etc.
