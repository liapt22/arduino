#ifndef INTERFON_H
#define INTERFON_H

#include <Arduino.h>
#include "srv_serial_stdio.hpp"
#include "led.hpp"
#include "keypad_config.hpp"
#include "lcd_config.hpp"


void interfon_init(void);
void interfon_process(void);

#endif
