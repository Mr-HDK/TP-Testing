
#include "sensor.h"
#include "controller.h"
#include "notifier.h"

int main(void) {
    while (1) {
        int sensor_value = read_sensor();

        if (is_valid_value(sensor_value)) {
            int processed_value = process_data(sensor_value);
            log_data(processed_value);
        } else {
            notify_threshold_exceeded(sensor_value);
        }
    }
    return 0;
}
