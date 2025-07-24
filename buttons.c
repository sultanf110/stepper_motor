#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include "motors.h"
#include "buttons.h"

int touchdown()
{
    int n;
   
    printf("Searching zero... ");

    while (sc_status()  == BUTTON_OFF)
    {
        revolve_motor(1, 1, MOTOR_N1, MOTOR_N2, MOTOR_N3, MOTOR_N4);
    }

    n = 0;
    printf("found. \n  Searching end.\n");
    delay(1000);

    while (ec_status() == BUTTON_OFF)
    {
        revolve_motor(1, 1, MOTOR_N4, MOTOR_N3, MOTOR_N2, MOTOR_N1);
        n++;
    }

    return n;

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
    wiringPiSetup();  

    pinMode(SC_PIN, INPUT);
    pinMode(EC_PIN, INPUT);

    pullUpDnControl(SC_PIN, PUD_UP); 
    pullUpDnControl(EC_PIN, PUD_UP); 
}
