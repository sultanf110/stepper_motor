#ifndef GET_POSITION_H 
#define GET_POSITION_H
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include "motors.h"


#define MOTOR_N1 0
#define MOTOR_N2 0
#define MOTOR_N3 0
#define MOTOR_N4 0

//the limits of the axis of movement
#define N_MAX 512
#define N_MIN 0

int get_position(int steps, int direction);