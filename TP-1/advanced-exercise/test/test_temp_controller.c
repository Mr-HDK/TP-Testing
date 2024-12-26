#include "unity.h"
#include "temp_controller.h"
#include "mock_temp_sensor.h"

#define TEMP_TOO_HOT 30
#define TEMP_TOO_COLD 15

void setUp(void) {
    mock_temp_sensor_Init();
}

void tearDown(void) {
    mock_temp_sensor_Verify();
    mock_temp_sensor_Destroy();
}

void test_check_temperature_should_return_1_when_too_hot(void) {
    read_temperature_sensor_ExpectAndReturn(31); 
    TEST_ASSERT_EQUAL(1, check_temperature());
}

void test_check_temperature_should_return_minus_1_when_too_cold(void) {
    read_temperature_sensor_ExpectAndReturn(14); 
    TEST_ASSERT_EQUAL(-1, check_temperature());
}

void test_check_temperature_should_return_0_when_normal(void) {
    read_temperature_sensor_ExpectAndReturn(22); 
    TEST_ASSERT_EQUAL(0, check_temperature());
}

void test_check_temperature_should_handle_exact_limits(void) {
    // Test lower limit
    read_temperature_sensor_ExpectAndReturn(15);
    TEST_ASSERT_EQUAL(0, check_temperature());

    // Test upper limit
    read_temperature_sensor_ExpectAndReturn(30);
    TEST_ASSERT_EQUAL(0, check_temperature());
}
