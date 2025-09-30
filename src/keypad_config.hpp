#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#include <Keypad.h>

#define PASSWORD_MAX_LENGTH 4
#define PASSWORD  "1234"
#define KEYPAD_ROWS 4
#define KEYPAD_COL  4

enum KEYPAD_PINS
{
    KEYPAD_PIN_1 = 23,
    KEYPAD_PIN_2 = 25,
    KEYPAD_PIN_3 = 27,
    KEYPAD_PIN_4 = 29,
    KEYPAD_PIN_5 = 31,
    KEYPAD_PIN_6 = 33,
    KEYPAD_PIN_7 = 35,
    KEYPAD_PIN_8 = 37

};


#endif
