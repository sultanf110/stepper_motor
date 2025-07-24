#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

///Modifiy this if you change input GPIO
#define MOTOR_N1 7
#define MOTOR_N2 0
#define MOTOR_N3 2
#define MOTOR_N4 3

void revolve_motor(int steps, int latency, int gpio1, int gpio2, int gpio3, int gpio4);
void disable_all_motors();
