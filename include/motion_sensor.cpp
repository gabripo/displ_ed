#include "motion_sensor.h"

void setup_motion_sensor() {
    pinMode(PIN_TO_SENSOR, INPUT);
}

void motion_sensor_read() {
    pinSensorStatePrevious = pinSensorStateCurrent;
    pinSensorStateCurrent = digitalRead(PIN_TO_SENSOR);
}

bool is_motion_started() {
    return (pinSensorStatePrevious == LOW && pinSensorStateCurrent == HIGH);
}

bool is_motion_finished() {
    return (pinSensorStatePrevious == HIGH && pinSensorStateCurrent == LOW);
}
