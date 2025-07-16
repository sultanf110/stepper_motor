## Description:
This project controls one or two 28BYJ-48 stepper motors using a Raspberry Pi and the ULN2003 driver board.

## Usage Requirements:
- Raspberry Pi 
- WiringPi library installed
- 28BYJ-48 stepper motor

## WiringPi Installation steps:
In terminal:

1. Clone the WiringPi repository using the command: git clone https://github.com/WiringPi/WiringPi.git
2. cd WiringPi
3. ./build
4. gpio -v to check if it was successfully installed

## Usage:
In order for your system to work, you will connect 4 wires (N1, N2, N3, N4) from your driver to 4 GPIOs on your Rasberry Pi.

Before compiling the code, make sure that you edit the pin definitions at the top of the code file to match your connections to the GPIOs. These lines:
```
#define MOTOR1_N1 7
#define MOTOR1_N2 0
#define MOTOR1_N3 2
#define MOTOR1_N4 3
#define MOTOR2_N1 26
#define MOTOR2_N2 27
#define MOTOR2_N3 27
#define MOTOR2_N4 28
#define MOTOR3_N1 11 //GPIO 7
#define MOTOR3_N2 10 //GPIO 8 
#define MOTOR3_N3 6 // GPIO 25
#define MOTOR3_N4 5 // GPIO 24
```
should be updated with the correct **WiringPi pin numbers** (and not the GPIO or the Pin numbers) that correspond to your motor connections.

You can refer to https://pinout.xyz or simply look it up to find the right mappings and conversions.
 
## Compilation:
The file takes the following as inputs:
- Motor: choose 1, 2, or 3 
- Number of steps: a full revolution of the motor requires 512 steps
- Latency: in milliseconds (ms)
- Direction: choose 0 for clockwise and 1 for counterclockwise


To compile, type the following commands in terminal: 

- ` gcc filename.c -o filename -l wiringPi  ` to compile using the wiringPi library
- ./stepper &lt;motor&gt; &lt;steps&gt; &lt;latency&gt; &lt;direction&gt;



## Example:
Example execution of motor 1 with a full revolution and 1 ms latency in the clockwise direction:

` ./test 1 512 1 0 `

