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

void Led::toggle() {
    digitalWrite(pinLed, !digitalRead(pinLed));
}
