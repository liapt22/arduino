#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Arduino.h>


void button_init(int pin);


bool button_is_pressed(int pin);


bool button_was_pressed(int pin, unsigned long debounce_ms);

#endif
