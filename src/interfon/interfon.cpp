#include "interfon.hpp"
#include <./keypad_config.hpp>
#include <./led.hpp>

void interfon_init(void) {
    srv_serial_setup();
    led_control_init(LED_RED_PIN, OUTPUT);
    led_control_init(LED_GREEN_PIN, OUTPUT);
}
void interfon_process(void) {
    char ch = 0;
    uint8_t char_count = 0;
    char password[PASSWORD_MAX_LENGTH + 1] = {0};

    printf("Password:\n");

    while (char_count < PASSWORD_MAX_LENGTH) {
        scanf("%c", &ch);        
        if (ch == '#') break;  

        password[char_count] = ch;
        printf("*");
        char_count++;
    }
    password[char_count] = '\0'; 

    
    if (strcmp(password, PASSWORD) == 0) {
        led_on(LED_GREEN_PIN);
        
    } else {
        led_on(LED_RED_PIN);
        
    }

    delay(3000);
    led_off(LED_RED_PIN);
    led_off(LED_GREEN_PIN);

    printf("\f");
}

