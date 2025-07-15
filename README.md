## Description:
This project controls one or two 28BYJ-48 stepper motors using a Raspberry Pi and the ULN2003 driver board.

## Usage Requirements:
- Raspberry Pi (any model with GPIO)
- WiringPi library installed
- 28BYJ-48 stepper motor

## WiringPi Installation steps:
1. Clone the WiringPi repository using the command: git clone https://github.com/WiringPi/WiringPi.git
2. cd WiringPi
3. ./build
4. gpio -v to check if it was successfully installed

## Usage:

## Compilation:
The file takes the following as inputs:
- Motor: choose 1 or 2  
- Number of steps: a full revolution of the motor requires 512 steps
- Latency: in milliseconds (ms)
- Direction: choose 0 for clockwise and 1 for counterclockwise

  
To compile, type the following command in terminal: **./stepper &lt;motor&gt; &lt;steps&gt; &lt;latency&gt; &lt;direction&gt;**


## Example:
Example execution of motor 1 with a full revolution and 1 ms latency in the clockwise direction:

` ./test 1 512 1 0 `
