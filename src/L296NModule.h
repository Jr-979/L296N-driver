#ifndef L296NModule_h
#define L296NModule_h
#include "Arduino.h"
#endif

class Driver
{
public:
    Driver(uint8_t EN, uint8_t INA, uint8_t INB);

    bool isForward;

    void begin(bool fastPWM = false);
    void setDirection(uint8_t dir);
    void setSpeed(uint8_t speed);
    void forward(uint8_t speed);
    void reverse(uint8_t speed);
    void freeWheeling();
    void fullyBreak();

private:
    uint8_t _EN;
    uint8_t _INA;
    uint8_t _INB;

};