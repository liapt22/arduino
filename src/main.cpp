// #include "Led.hpp"
// #include "srv_serial_stdio.hpp"
// #include <string.h>
// #include "keypad_config.hpp"
// #include <interfon/interfon.cpp>

// // Led led2(13); // LED intern pin 13

// void setup() {
//     srv_serial_setup();
//     // printf("System ready. LED is OFF\n");
// }

// void loop() {

//     //lab1
//     // char command[100];
//     // printf("Enter a command: ");
//     // fflush(stdout); // forțează afișarea mesajului în terminal

//     // scanf("%s", command);

//     // if (strcmp(command, "ledon") == 0) {
//     //     led2.turnOn();
//     //     printf("LED turned ON\n");
//     // } else if (strcmp(command, "ledoff") == 0) {
//     //     led2.turnOff();
//     //     printf("LED turned OFF\n");
//     // } else {
//     //     printf("Invalid command: %s\n", command);
//     // }

//     //lab2

//       int key = keypad_get_char(NULL);  // citește tasta de la Keypad
//     if (key != -1) {                  // dacă s-a apăsat o tastă
//         printf("%c", key); 
        
        
// delay(200);
//  }}

#include <Arduino.h>
#include "interfon/interfon.hpp"

void setup() {
    interfon_init();
}

void loop() {
    interfon_process();

}

