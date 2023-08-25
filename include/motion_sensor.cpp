#include "motion_sensor.h"

void setup_motion_sensor() {
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), motion_event, CHANGE);
}

void motion_event() {
    isMotion = !isMotion;
}