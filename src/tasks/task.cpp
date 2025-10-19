#include <Arduino.h>
#include "../Led.hpp"
#include "../srv_serial_stdio.hpp"

#define FIRST_LED_PIN 13
#define SECOND_LED_PIN 12

#define BUTTON_TOGGLE_PIN 10  
#define BUTTON_INC_PIN 9     
#define BUTTON_DEC_PIN 8     

static Led led1(FIRST_LED_PIN);
static Led led2(SECOND_LED_PIN);

volatile bool sig_button_toggle = false;
volatile bool sig_inc = false;
volatile bool sig_dec = false;

static bool led1_state = false;
static bool led2_state = false;
static unsigned long blink_time = 300; 
static unsigned long last_blink_time = 0;

static const unsigned long DEBOUNCE_MS = 50;

void buttons_init() {
    pinMode(BUTTON_TOGGLE_PIN, INPUT_PULLUP);
    pinMode(BUTTON_INC_PIN, INPUT_PULLUP);
    pinMode(BUTTON_DEC_PIN, INPUT_PULLUP);
}

static void task_button_toggle() {
    static bool last_state = HIGH;
    bool current = digitalRead(BUTTON_TOGGLE_PIN);
    if (last_state == HIGH && current == LOW) {
        led1_state = !led1_state;
        if (led1_state) led1.turnOn();
        else led1.turnOff();

        printf("[EVENT] Toggle button pressed → LED1 is now %s\n", led1_state ? "ON" : "OFF");

        sig_button_toggle = true;
        delay(150); // mic anti-rebound
    }
    last_state = current;
}

static void task_adjust_blink_time() {
    if (!led1_state) {
        if (digitalRead(BUTTON_INC_PIN) == LOW) { 
            if (blink_time < 5000) blink_time += 200; 
            sig_inc = true;
            printf("[EVENT] Increase button pressed → Blink time = %lu ms\n", blink_time);
            delay(150);
        }
        if (digitalRead(BUTTON_DEC_PIN) == LOW) { 
            if (blink_time > 50) blink_time -= 200; 
            sig_dec = true;
            printf("[EVENT] Decrease button pressed → Blink time = %lu ms\n", blink_time);
            delay(150);
        }
    }
}

static void task_led_blink() {
    if (!led1_state) {
        unsigned long now = millis();
        if (now - last_blink_time >= blink_time) {
            led2_state = !led2_state;
            if (led2_state) led2.turnOn();
            else led2.turnOff();
            last_blink_time = now;
        }
    } else {
        if (led2_state) {
            led2_state = false;
            led2.turnOff();
        }
    }
}

void idle_task() {
    // Rulăm task-urile
    task_button_toggle();
    task_adjust_blink_time();
    task_led_blink();

    // Detectăm evenimentele și le afișăm în terminal
    if (sig_button_toggle) {
        printf("[EVENT] Toggle button pressed → LED1 is %s\n",
               led1_state ? "ON" : "OFF");
        sig_button_toggle = false;
    }

    if (sig_inc) {
        printf("[EVENT] Increase button pressed → Blink = %lu ms\n", blink_time);
        sig_inc = false;
    }

    if (sig_dec) {
        printf("[EVENT] Decrease button pressed → Blink = %lu ms\n", blink_time);
        sig_dec = false;
    }

    delay(20); // mică pauză pentru stabilitate
}


void tasks_init() {
    buttons_init();
    led1.turnOff();
    led2.turnOff();
    printf("Tasks initialized. Toggle=%d, INC=%d, DEC=%d\n", BUTTON_TOGGLE_PIN, BUTTON_INC_PIN, BUTTON_DEC_PIN);
}
