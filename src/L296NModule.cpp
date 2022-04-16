#include "L296NModule.h"


// Initialize EN , INA , INB
Driver::Driver(uint8_t EN, uint8_t INA, uint8_t INB)
{
	_EN = EN;
	_INA = INA;
	_INB = INB;
    isForward = true;

}

///Init motor driver fastPWM for pin 5,6 will affects Delay Function
void Driver::begin(bool fastPWM = false){

    if (fastPWM){
        if (_EN == 9 || _EN == 10){
            TCCR1B = TCCR1B & B11111000 | B00000001; //PWM frequency of 31372.55 Hz
        }
        else if((_EN == 3 || _EN == 11)){
            TCCR2B = TCCR2B & B11111000 | B00000001; //PWM frequency of 31372.55 Hz
        }
        else if((_EN == 5 || _EN == 6)){
            TCCR0B = TCCR2B & B11111000 | B00000001; //PWM frequency of 62500.00 Hz
        }
    }
    pinMode(_EN, OUTPUT);
    pinMode(_INA, OUTPUT);
    pinMode(_INB, OUTPUT);
}
///Set a motor Speed PWM
void Driver::setSpeed(uint8_t speed){
    analogWrite(_EN, speed); 
    digitalWrite(_INA, !isForward);
    digitalWrite(_INB, isForward);
}
///Rotate forward 
void Driver::forward(uint8_t speed){
    isForward = true;
    this->setSpeed(speed);
}

///Rotate reverse 
void Driver::reverse(uint8_t speed){
    isForward = false;
    this->setSpeed(speed);
}

///Lets motor rotate by inertia
void Driver::freeWheeling(){
    analogWrite(_EN,0);
    digitalWrite(_INA, LOW);
    digitalWrite(_INB, LOW);
}

///Instantly breake the motor
void Driver::fullyBreak(){
    analogWrite(_EN,0);
    digitalWrite(_INA, HIGH);
    digitalWrite(_INB, HIGH);
}

///Set A rotating Direction 1 Forward 0 Reverse -1 Toggle
void Driver::setDirection(uint8_t dir){

    isForward != -1 ? isForward = dir : isForward = !isForward;


}
