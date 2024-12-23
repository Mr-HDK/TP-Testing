#include "unity.h"
#include "sensor.h"
#include "controller.h"
#include "notifier.h"
#include "utils.h"
#include <stdlib.h>

void setUp(void) {
    srand(42); // Initialize the random number generator for reproducibility
}

void tearDown(void) {}

// Test: Workflow with valid sensor values
void test_valid_sensor_value_workflow(void) {
    for (int i = 0; i < 20; i++) {
        int sensor_value = read_sensor();
        if (sensor_value > 0 && sensor_value < 100) {
            int processed_value = process_data(sensor_value); // Process the sensor value
            log_data(processed_value); // Log the processed data
            TEST_ASSERT_EQUAL_INT(sensor_value * 2 + 10, processed_value); // Verify the processed result
        }
    }
}

// Test: Workflow with invalid sensor values
void test_invalid_sensor_value_workflow(void) {
    for (int i = 0; i < 20; i++) {
        int sensor_value = read_sensor();
        if (!is_valid_value(sensor_value)) { // Condition for out-of-range values
            notify_threshold_exceeded(sensor_value); // Trigger an alert for invalid values
            TEST_ASSERT_FALSE(is_valid_value(sensor_value)); // Verify that the value is invalid
        }
    }
}

// Test: Boundary conditions
void test_boundary_conditions(void) {
    int boundary_values[] = {0, 100, -1, 101, 149}; // Boundary valid and invalid values
    for (int i = 0; i < sizeof(boundary_values) / sizeof(boundary_values[0]); i++) {
        int sensor_value = boundary_values[i];
        if (is_valid_value(sensor_value)) {
            int processed_value = process_data(sensor_value); // Process the sensor value
            log_data(processed_value); // Log the processed data
            TEST_ASSERT_EQUAL_INT(sensor_value * 2 + 10, processed_value); // Verify the processed result
        } else {
            notify_threshold_exceeded(sensor_value); // Trigger an alert for invalid values
            TEST_ASSERT_FALSE(is_valid_value(sensor_value)); // Verify that the value is invalid
        }
    }
}
