
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

#define MOTOR1_N1 7
#define MOTOR1_N2 0
#define MOTOR1_N3 2
#define MOTOR1_N4 3
#define MOTOR2_N1 26
#define MOTOR2_N2 27
#define MOTOR2_N3 27
#define MOTOR2_N4 28
#define MOTOR3_N1 11
#define MOTOR3_N2 10
#define MOTOR3_N3 6
#define MOTOR3_N4 5

void disable_all_motors();
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

	disable_all_motors();
	
	if (choice == 1)
	{
		if (direction == 0)
		{
			revolve_motor(steps, latency, MOTOR1_N1, MOTOR1_N2, MOTOR1_N3, MOTOR1_N4);
		}
		else{
			revolve_motor(steps, latency, MOTOR1_N4, MOTOR1_N3, MOTOR1_N2, MOTOR1_N1);
		}
	}
	else if (choice == 2)
	{
		if (direction == 0)
		{
			revolve_motor(steps, latency, MOTOR2_N1, MOTOR2_N2, MOTOR2_N3, MOTOR2_N4);
		}
		else{
			revolve_motor(steps, latency, MOTOR2_N4, MOTOR2_N3, MOTOR2_N2, MOTOR2_N1);
		}
	}
	else if (choice == 3)
	{
		if (direction == 0)
		{
			revolve_motor(steps, latency, MOTOR3_N1, MOTOR3_N2, MOTOR3_N3, MOTOR3_N4);
		}
		else{
			revolve_motor(steps, latency, MOTOR3_N4, MOTOR3_N3, MOTOR3_N2, MOTOR3_N1);
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


