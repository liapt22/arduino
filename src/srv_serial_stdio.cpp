#include "srv_serial_stdio.hpp"
#include <stdio.h>

static int serial_putchar(char c, FILE* f) {
    if (c == '\n') Serial.write('\r'); // adaugă CR pentru terminale care cer CR+LF
    Serial.write(c);
    return 0;
}

void srv_serial_setup() {
    Serial.begin(9600);
    delay(500);

    static FILE serial_stdout;
    fdev_setup_stream(&serial_stdout, serial_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &serial_stdout; // redirecționează printf către Serial

    printf("[INIT] printf() redirection OK!\n");
}
