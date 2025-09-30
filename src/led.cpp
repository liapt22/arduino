#include "Led.hpp"

Led::Led(int pin) {
    pinLed = pin;
    pinMode(pinLed, OUTPUT);
    digitalWrite(pinLed, LOW); 
}

void Led::turnOn() {
    digitalWrite(pinLed, HIGH); 
}

void Led::turnOff() {
    digitalWrite(pinLed, LOW);  
}

void led_control_init(int pin, int mode) {
    pinMode(pin, mode);
    digitalWrite(pin, LOW);      
}

void led_on(int pin) {
    digitalWrite(pin, HIGH);
}

void led_off(int pin) {
    digitalWrite(pin, LOW);
}
