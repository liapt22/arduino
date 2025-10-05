#include "button.hpp"

void button_init(int pin) {
    pinMode(pin, INPUT_PULLUP);
}

bool button_is_pressed(int pin) {
    return digitalRead(pin) == LOW;
}

bool button_was_pressed(int pin, unsigned long debounce_ms) {
    static bool last_state[54] = {false};
    static unsigned long last_time[54] = {0};
    static bool edge_reported[54] = {false};

    if (pin < 0 || pin >= 54) {
        bool cur = button_is_pressed(pin);
        return cur;
    }

    bool cur = (digitalRead(pin) == LOW);
    unsigned long now = millis();
    if (cur != last_state[pin]) {
        last_time[pin] = now;
        last_state[pin] = cur;
        edge_reported[pin] = false; 
    }
    if (!edge_reported[pin] && cur == true && (now - last_time[pin] >= debounce_ms)) {
        edge_reported[pin] = true; 
        return true;
    }

    return false;
}
