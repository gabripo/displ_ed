#include <Arduino.h>

#define PIN_TO_SENSOR 2  // Has to be an interrupt-capable pin!
const byte interruptPin = 2;

volatile byte isMotion;

void setup_motion_sensor();
void motion_event();