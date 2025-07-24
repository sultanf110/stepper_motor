#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include "motors.h"

///Modifiy this if you change input GPIO
#define SC_PIN 24
#define EC_PIN 15

#define BUTTON_OFF 0

int sc_status();
int ec_status();
int touchdown();
void setup_switch_pins();