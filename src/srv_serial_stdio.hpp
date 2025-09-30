#ifndef SRV_SERIAL_STDIO_H
#define SRV_SERIAL_STDIO_H
#include <LiquidCrystal_I2C.h> 
#include <Keypad.h>
#include <Arduino.h>
#include <stdio.h>

int keypad_get_char(FILE *stream);
int lcd_put_char(char c, FILE *stream);
int srv_serial_get_char(FILE *stream);
int srv_serial_put_char(char c, FILE *stream);
void srv_serial_setup();
void own_stdio_init(int val);
#endif
