#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include "motors.h"

void revolve_motor(int steps, int latency, int gpio1, int gpio2, int gpio3, int gpio4)
{
	wiringPiSetup();
	
	int controlPins[4] = {gpio1, gpio2, gpio3, gpio4};

	int stepSequence[8][4] = {
	{1, 0, 0, 0},
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
	{0, 0, 0, 1}
	};

	for (int i = 0; i < 4 ; i++)
	{
		pinMode(controlPins[i], OUTPUT);
		digitalWrite(controlPins[i], LOW);
	}

	for (int step = 0; step < steps; step++)
	{
		for (int halfstep = 0; halfstep<8; halfstep++)
		{
			for (int pin = 0; pin<4; pin++)
			{
				digitalWrite(controlPins[pin], stepSequence[halfstep][pin]);
			}
		delay(latency);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		digitalWrite(controlPins[i], LOW);
	}
}

void disable_all_motors()
{
    int allPins[] = {
        MOTOR1_N1, MOTOR1_N2, MOTOR1_N3, MOTOR1_N4,
        MOTOR2_N1, MOTOR2_N2, MOTOR2_N3, MOTOR2_N4,
        MOTOR3_N1, MOTOR3_N2, MOTOR3_N3, MOTOR3_N4
    };

    int totalPins = sizeof(allPins) / sizeof(allPins[0]);

    for (int i = 0; i < totalPins; i++) {
        pinMode(allPins[i], OUTPUT);          // Ensure it's set as output
        digitalWrite(allPins[i], LOW);        // Turn it off
    }
}