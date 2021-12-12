# kame
8DOF quadrupet robot controlled with ESP32 board.
Connection via Wifi and telnet protocol.

Web-Page is coming.


<img src="/doc/images/kame_stand.jpg" width="45%"></img>




Board pins can be set to match this scheme in the function init of minikame library. Example:
````
board_pins[0] = D1; // Servo S0
board_pins[1] = D4; // Servo S1
board_pins[2] = D8; // Servo S2
board_pins[3] = D6; // Servo S3
board_pins[4] = D7; // Servo S4
board_pins[5] = D5; // Servo S5
board_pins[6] = D2; // Servo S6
board_pins[7] = D3; // Servo S7
````

## License
This project was build upon the great work from [JavierIH](https://github.com/JavierIH/miniKame)
