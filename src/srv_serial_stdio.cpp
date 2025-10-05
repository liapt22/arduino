#include "srv_serial_stdio.hpp"

void srv_serial_setup() {
    Serial.begin(9600);
    while (!Serial) {} 
}

extern "C" int _write(int file, char *ptr, int len) {
    (void)file;
    for (int i = 0; i < len; i++) Serial.write(ptr[i]);
    return len;
}
