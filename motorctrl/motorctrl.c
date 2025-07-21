#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

#define MOTOR1_N1 25
#define MOTOR1_N2 24
#define MOTOR1_N3 23
#define MOTOR1_N4 22
#define MOTOR2_N1 0
#define MOTOR2_N2 7
#define MOTOR2_N3 9
#define MOTOR2_N4 8
#define MOTOR3_N1 4
#define MOTOR3_N2 1
#define MOTOR3_N3 16
#define MOTOR3_N4 15

void revolve_motor(int steps, int latency, int gpio1, int gpio2, int gpio3, int gpio4);

void MotorCtrl(int motor, int steps, int latency, int direction)
{
    int gpio1, gpio2, gpio3, gpio4;

    switch (motor) {
        case 1:
            gpio1 = direction == 0 ? MOTOR1_N1 : MOTOR1_N4;
            gpio2 = direction == 0 ? MOTOR1_N2 : MOTOR1_N3;
            gpio3 = direction == 0 ? MOTOR1_N3 : MOTOR1_N2;
            gpio4 = direction == 0 ? MOTOR1_N4 : MOTOR1_N1;
            break;
        case 2:
            gpio1 = direction == 0 ? MOTOR2_N1 : MOTOR2_N4;
            gpio2 = direction == 0 ? MOTOR2_N2 : MOTOR2_N3;
            gpio3 = direction == 0 ? MOTOR2_N3 : MOTOR2_N2;
            gpio4 = direction == 0 ? MOTOR2_N4 : MOTOR2_N1;
            break;
        case 3:
            gpio1 = direction == 0 ? MOTOR3_N1 : MOTOR3_N4;
            gpio2 = direction == 0 ? MOTOR3_N2 : MOTOR3_N3;
            gpio3 = direction == 0 ? MOTOR3_N3 : MOTOR3_N2;
            gpio4 = direction == 0 ? MOTOR3_N4 : MOTOR3_N1;
            break;
        default:
            printf("Invalid motor number: %d\n", motor);
            return;
    }

    revolve_motor(steps, latency, gpio1, gpio2, gpio3, gpio4);
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

    for (int i = 0; i < 4 ; i++) {
        pinMode(controlPins[i], OUTPUT);
        digitalWrite(controlPins[i], LOW);
    }

    for (int step = 0; step < steps; step++) {
        for (int halfstep = 0; halfstep < 8; halfstep++) {
            for (int pin = 0; pin < 4; pin++) {
                digitalWrite(controlPins[pin], stepSequence[halfstep][pin]);
            }
            delay(latency);
        }
    }

    for (int i = 0; i < 4; i++) {
        digitalWrite(controlPins[i], LOW);
    }
}
