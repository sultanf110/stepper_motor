#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include "motors.h"

#define MOTOR_N1 0
#define MOTOR_N2 0
#define MOTOR_N3 0
#define MOTOR_N4 0

int get_position(int steps, int direction)
{
    int position = 0;

    if (direction == 0)
    {
        while(revolve_motor(steps, 1, MOTOR_N1, MOTOR_N2, MOTOR_N3, MOTOR_N4))
        {
            position = position + steps;
        }
    }
    else
    {
        while(revolve_motor(steps, 1, MOTOR_N4, MOTOR_N3, MOTOR_N2, MOTOR_N1))
        {
            position = position + steps;
        }
    }

    return position;
}