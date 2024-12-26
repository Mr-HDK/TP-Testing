#include "temp_controller.h"
#include "temp_sensor.h"

int check_temperature(void) {
    int temperature = read_temperature_sensor();

    if (temperature < -40 || temperature > 125) {
        return -99; // Indicating sensor error
    }

    if (temperature > 30) {
        return 1; // Too hot
    } else if (temperature < 15) {
        return -1; // Too cold
    } else {
        return 0; // Normal temperature
    }
}

