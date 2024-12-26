#include "build/test/mocks/mock_temp_sensor.h"
#include "src/temp_controller.h"
#include "C:/Users/KhaoulaBT/.local/share/gem/ruby/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {



    mock_temp_sensor_Init();

}



void tearDown(void) {



    mock_temp_sensor_Verify();

    mock_temp_sensor_Destroy();

}



void test_check_temperature_should_return_1_when_too_hot(void) {

    read_temperature_sensor_CMockExpectAndReturn(17, 45);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_minus_1_when_too_cold(void) {

    read_temperature_sensor_CMockExpectAndReturn(22, 14);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_0_when_normal(void) {

    read_temperature_sensor_CMockExpectAndReturn(27, 20);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}







void test_check_temperature_should_handle_exact_limits(void) {

    read_temperature_sensor_CMockExpectAndReturn(34, 40);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);



    read_temperature_sensor_CMockExpectAndReturn(37, 10);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);





}
