#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include "buttons.h"
#include "motors.h"

int main()
{
    int n;

    setup_switch_pins();   

    n = touchdown();
    printf("The value of n is %d \n", n);
    return 0;
}
