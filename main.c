#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

void revolve_motor(int steps, int latency, int, int, int, int); //revolving motor func

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		printf("Usage:   %s <motor> <steps> <latency> <direction>\n", argv[0]);
		return -1;
	}
	
	int choice, steps, latency, direction;
	
	choice = atoi(argv[1]);
	steps = atoi(argv[2]);
	latency = atoi(argv[3]);
	direction = atoi(argv[4]);
	
	if (choice == 1)
	{
		if (direction == 0)
		{
			revolve_motor(steps, latency, 0, 2, 3, 7);
		}
		else{
			revolve_motor(steps, latency, 7, 3, 2, 0);
		}
	}
	else
	{
		if (direction == 0)
		{
			revolve_motor(steps, latency, 26, 27, 28, 29);
		}
		else{
			revolve_motor(steps, latency, 29, 28, 27, 26);
		}
	}
	
	return 0;
}

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
