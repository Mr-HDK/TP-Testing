#include "build/test/mocks/mock_temp_sensor.h"
#include "src/temp_controller.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {



    mock_temp_sensor_Init();

}



void tearDown(void) {





    mock_temp_sensor_Verify();

    mock_temp_sensor_Destroy();

}



void test_check_temperature_should_return_1_when_too_hot(void) {

    read_temperature_sensor_CMockExpectAndReturn(18, 31);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_minus_1_when_too_cold(void) {

    read_temperature_sensor_CMockExpectAndReturn(23, 10);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_0_when_normal(void) {

    read_temperature_sensor_CMockExpectAndReturn(28, 22);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

}







void test_check_temperature_should_handle_exact_limits(void) {

    read_temperature_sensor_CMockExpectAndReturn(35, 15);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);



    read_temperature_sensor_CMockExpectAndReturn(38, 30);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);





}

void test_check_temperature_should_handle_extreme_values(void) {



    read_temperature_sensor_CMockExpectAndReturn(54, -50);

    UnityAssertEqualNumber((UNITY_INT)((-2)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);





    read_temperature_sensor_CMockExpectAndReturn(58, 220);

    UnityAssertEqualNumber((UNITY_INT)((-2)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}
