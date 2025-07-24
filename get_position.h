#ifndef GET_POSITION_H 
#define GET_POSITION_H
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include "motors.h"

int get_position(int steps, int direction);