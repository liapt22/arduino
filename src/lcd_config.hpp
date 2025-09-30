#ifndef CONFIGS_H
#define CONFIGS_H
#include <LiquidCrystal_I2C.h> 


#define LCD_ADDRESS 0x27        // Adresa I2C a LCD-ului
#define LCD_COLUMNS 16         // Număr de coloane ale LCD-ului
#define LCD_ROWS 2              // Număr de rânduri ale LCD-ului

extern LiquidCrystal_I2C lcd;
#endif
