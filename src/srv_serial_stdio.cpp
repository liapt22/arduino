#include "srv_serial_stdio.hpp"
#include "keypad_config.hpp"
#include "lcd_config.hpp"
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// DEFINIȚII GLOBALE (o singură dată)
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

char keys[KEYPAD_ROWS][KEYPAD_COL] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[KEYPAD_ROWS] = {KEYPAD_PIN_1, KEYPAD_PIN_2, KEYPAD_PIN_3, KEYPAD_PIN_4};
byte colPins[KEYPAD_COL] = {KEYPAD_PIN_5, KEYPAD_PIN_6, KEYPAD_PIN_7, KEYPAD_PIN_8};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COL);

int col = 0;  
int row = 0;  

int lcd_put_char(char c, FILE *stream) {
    if (c == '\f') {
        lcd.clear();
        lcd.setCursor(0, 0);
        return 0;
    }
    if (c == '\n') {
        static int current_row = 0;
        current_row = (current_row + 1) % LCD_ROWS;
        lcd.setCursor(0, current_row);
        return 0;
    }

    lcd.write(c);
    return c;
}

int keypad_get_char(FILE *stream) {
    char key = 0;
    // Așteaptă până când se apasă o tastă
    while ((key = kpd.getKey()) == NO_KEY) {
        delay(10);
    }
    return key;
}

static FILE lcd_stream;

void srv_serial_setup() {
    lcd.init();
    lcd.backlight();
    fdev_setup_stream(&lcd_stream, lcd_put_char, keypad_get_char, _FDEV_SETUP_RW);
    stdin  = &lcd_stream;
    stdout = &lcd_stream;
}

void own_stdio_init(int mode) {
    Serial.begin(9600);
}

// int srv_serial_get_char(FILE *stream) {
//     while (Serial.available() == 0); 
//     char c = Serial.read();
//     Serial.write(c); 
//     return c;
// }

// int srv_serial_put_char(char c, FILE *stream) {
//     Serial.write(c);
//     return 0;
// }

