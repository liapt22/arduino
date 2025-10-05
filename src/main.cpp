#include <Arduino.h>
#include "srv_serial_stdio.hpp"
#include "tasks/task.hpp"

void setup() {
    srv_serial_setup();
    tasks_init();
    
}

void loop() {
 
    idle_task();
}
