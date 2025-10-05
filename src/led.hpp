#ifndef LED_H
#define LED_H


#include <Arduino.h>

class Led {
private:
    int pinLed;
public:
    Led(int pin);
    void turnOn();
    void turnOff();
    void toggle();
};


#endif
