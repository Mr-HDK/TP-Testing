#include "mock_temp_sensor.h"
#include "src/temp_controller.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {





}



void tearDown(void) {





}



void test_check_temperature_should_return_1_when_too_hot(void) {

    read_temperature_sensor_CMockExpectAndReturn(16, );

    UnityAssertEqualNumber((UNITY_INT)(()), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_minus_1_when_too_cold(void) {

    read_temperature_sensor_CMockExpectAndReturn(21, );

    UnityAssertEqualNumber((UNITY_INT)(()), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_0_when_normal(void) {

    read_temperature_sensor_CMockExpectAndReturn(26, );

    UnityAssertEqualNumber((UNITY_INT)(()), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

}







void test_check_temperature_should_handle_exact_limits(void) {

    read_temperature_sensor_CMockExpectAndReturn(33, );

    UnityAssertEqualNumber((UNITY_INT)(()), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);



    read_temperature_sensor_CMockExpectAndReturn(36, );

    UnityAssertEqualNumber((UNITY_INT)(()), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);





}
