#include <Arduino.h>

const byte interruptPin = 2;  // Has to be an interrupt-capable pin!

volatile byte isMotion;

void setup_motion_sensor();
void motion_event();

// Specific doc website: https://arduinogetstarted.com/tutorials/arduino-motion-sensor?utm_content=cmp-true