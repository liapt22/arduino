#include "srv_serial_stdio.hpp"
#include "tasks/task.hpp"
void setup() {
    // Inițializare Serial + printf
    srv_serial_setup();
    printf("System initialized! millis=%lu\n", millis());

    // Inițializare pinii și taskurile
    tasks_init();   // dacă ai o funcție care setează pinMode pentru LED-uri și butoane
}

void loop() {
    idle_task();   }