#ifndef SENSOR_H
#define SENSOR_H

#include <stdbool.h>

int read_sensor(void);
bool is_valid_value(int value);

#endif
