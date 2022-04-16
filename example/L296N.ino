#include <Arduino.h>
#include "L296NModule.h"

uint8_t IN1 = 2;
uint8_t IN2 = 3;
uint8_t ENA = 9; 


uint8_t IN3 = 4;
uint8_t IN4 = 5;
uint8_t ENB = 10; 

Driver motorLeft(ENA,IN1,IN2);
Driver motorRight(ENB,IN3,IN4);

void setup()
{
    motorLeft.begin();
    motorRight.begin();

}

void loop()
{
    motorLeft.setDirection(-1); //Toggle motor's Direction
    motorRight.setDirection(-1);

    motorLeft.setSpeed(255); // Set motor to max speed
    motorRight.setSpeed(255);

    delay(5000);

    motorLeft.fullyBreak(); // Break the motor
    motorRight.fullyBreak();

    delay(5000);

}