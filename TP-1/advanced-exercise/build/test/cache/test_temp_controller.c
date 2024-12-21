#include "build/test/mocks/mock_temp_sensor.h"
#include "src/temp_controller.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {



    mock_temp_sensor_Init();

}



void tearDown(void) {



    mock_temp_sensor_Destroy();

}



void test_check_temperature_should_return_1_when_too_hot(void) {



    read_temperature_sensor_CMockExpectAndReturn(17, 85);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_minus_1_when_too_cold(void) {



    read_temperature_sensor_CMockExpectAndReturn(23, -5);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_0_when_normal(void) {



    read_temperature_sensor_CMockExpectAndReturn(29, 25);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_handle_exact_limits(void) {



    read_temperature_sensor_CMockExpectAndReturn(35, 0);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);





    read_temperature_sensor_CMockExpectAndReturn(39, 80);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_handle_sensor_failure(void) {



    read_temperature_sensor_CMockExpectAndReturn(45, 130);

    UnityAssertEqualNumber((UNITY_INT)((-2)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);



    read_temperature_sensor_CMockExpectAndReturn(48, -50);

    UnityAssertEqualNumber((UNITY_INT)((-2)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

}
