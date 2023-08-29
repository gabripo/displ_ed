#include "motion_sensor.h"

void setup_motion_sensor() {
    isMotion = 0;
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), motion_event, HIGH);  // Sensor in Repeatable Trigger mode!
}

void motion_event() {
    isMotion = !isMotion;
}