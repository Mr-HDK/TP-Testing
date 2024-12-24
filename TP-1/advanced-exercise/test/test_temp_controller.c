#include "unity.h"
#include "temp_controller.h"
#include "mock_temp_sensor.h"


#define TEMP_TOO_HOT 80
#define TEMP_TOO_COLD 0
#define TEMP_SENSOR_ERROR_HIGH 126
#define TEMP_SENSOR_ERROR_LOW -41

void setUp(void) {
    
    mock_temp_sensor_Init();
}

void tearDown(void) {
    
    mock_temp_sensor_Verify();
    mock_temp_sensor_Destroy();
}


void test_check_temperature_should_return_1_when_too_hot(void) {
    read_temperature_sensor_ExpectAndReturn(85); 
    TEST_ASSERT_EQUAL(1, check_temperature());
}


void test_check_temperature_should_return_minus_1_when_too_cold(void) {
    read_temperature_sensor_ExpectAndReturn(-10); 
    TEST_ASSERT_EQUAL(-1, check_temperature());
}


void test_check_temperature_should_return_0_when_normal(void) {
    read_temperature_sensor_ExpectAndReturn(25); 
    TEST_ASSERT_EQUAL(0, check_temperature());
}


void test_check_temperature_should_handle_exact_limits(void) {
    
    read_temperature_sensor_ExpectAndReturn(TEMP_TOO_COLD);
    TEST_ASSERT_EQUAL(-1, check_temperature());

   
    read_temperature_sensor_ExpectAndReturn(TEMP_TOO_HOT);
    TEST_ASSERT_EQUAL(1, check_temperature());
}


void test_check_temperature_should_return_error_for_sensor_failure(void) {
    
    read_temperature_sensor_ExpectAndReturn(TEMP_SENSOR_ERROR_LOW);
    TEST_ASSERT_EQUAL(-1, check_temperature());

   
    read_temperature_sensor_ExpectAndReturn(TEMP_SENSOR_ERROR_HIGH);
    TEST_ASSERT_EQUAL(1, check_temperature());
}
