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
};
void led_control_init(int pin, int mode);

#define LED_RED_PIN A0
#define LED_GREEN_PIN A3

void led_on(int pin);
void led_off(int pin);

#endif
