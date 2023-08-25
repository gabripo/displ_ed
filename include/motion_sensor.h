#include <Arduino.h>

#define PIN_TO_SENSOR 7

int pinSensorStateCurrent;
int pinSensorStatePrevious;

void setup_motion_sensor();
void motion_sensor_read();
bool is_motion_started();
bool is_motion_finished();