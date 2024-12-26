#include "unity.h"
#include "controller.h"
#include "sensor.h"

void setUp(void) {}
void tearDown(void) {}

void test_sensor_and_controller_integration(void) {
    int sensor_value = read_sensor(); // Get sensor data
    printf("Sensor Value: %d\n", sensor_value);
    if (is_valid_value(sensor_value)) {
        int processed_value = process_data(sensor_value); // Process data
        TEST_ASSERT_EQUAL(sensor_value * 2 + 10, processed_value);
    } else {
        TEST_FAIL_MESSAGE("Invalid sensor value encountered.");
    }
}


void test_process_data_handles_edge_cases(void) {
    TEST_ASSERT_EQUAL(10, process_data(0));  // Edge case: Lowest valid input
    TEST_ASSERT_EQUAL(210, process_data(100)); // Edge case: Highest valid input
}
