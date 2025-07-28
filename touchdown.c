#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

#define MOTOR_N1 7
#define MOTOR_N2 0
#define MOTOR_N3 2
#define MOTOR_N4 3

#define SC_PIN 24
#define EC_PIN 15

#define BUTTON_OFF 1

#define INTERRUPT_PIN 11

int sc_status();
int ec_status();
int touchdown();
void revolve_motor();
void setup_switch_pins();
void setup_interruption_pins();
void kill_program();

volatile int kill_signal = 0;

int main()
{
    int n;

    wiringPiSetup();
    setup_switch_pins();
    setup_interruption_pins();

    
    n = touchdown();    
    
    if (kill_signal)
    {
        printf("program was terminated \n");
    }

    printf(" %d \n", n);
    return 0;
}

int touchdown()
{
    int n;

    while (sc_status() == BUTTON_OFF && !kill_signal)
    {
        revolve_motor(1, 1, MOTOR_N1, MOTOR_N2, MOTOR_N3, MOTOR_N4);
    }

    n = 0;

    while (ec_status() == BUTTON_OFF && !kill_signal)
    {
        revolve_motor(1, 1, MOTOR_N4, MOTOR_N3, MOTOR_N2, MOTOR_N1);
        n++;
    }

    return n;

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

int sc_status()
{
    int x;

    if(digitalRead(SC_PIN) == 1)
    {
        x = 1; //button is pressed
    }
    else
    {
        x = 0;
    }

    return x;
}

int ec_status()
{
    int x;

    if(digitalRead(EC_PIN) == 1)
    {
        x = 1; 
    }
    else
    {
        x = 0;
    }
    
    return x;
}

void setup_switch_pins() 
{  
    pinMode(SC_PIN, INPUT);
    pinMode(EC_PIN, INPUT);

    pullUpDnControl(SC_PIN, PUD_UP); 
    pullUpDnControl(EC_PIN, PUD_UP); 
}

void setup_interruption_pins()
{
    pinMode(INTERRUPT_PIN, INPUT);
    pullUpDnControl(INTERRUPT_PIN, PUD_UP); 

    wiringPiISR(INTERRUPT_PIN, INT_EDGE_FALLING, &kill_program);
}

void kill_program()
{
    kill_signal = 1;
    printf("aborting program ... \n");
}
