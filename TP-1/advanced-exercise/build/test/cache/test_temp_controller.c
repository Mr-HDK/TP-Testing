#include "build/test/mocks/mock_temp_sensor.h"
#include "src/temp_controller.h"
#include "/home/rawaa/.rbenv/versions/2.7.8/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {

    mock_temp_sensor_Init();

}



void tearDown(void) {

    mock_temp_sensor_Verify();

    mock_temp_sensor_Destroy();

}



void test_check_temperature_should_return_1_when_too_hot(void) {

<<<<<<< HEAD
    read_temperature_sensor_CMockExpectAndReturn(15, 35);
=======


    read_temperature_sensor_CMockExpectAndReturn(16, 35);
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

<<<<<<< HEAD
   ), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT);
=======
   ), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_INT);
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

}



void test_check_temperature_should_return_minus_1_when_too_cold(void) {

<<<<<<< HEAD
    read_temperature_sensor_CMockExpectAndReturn(20, 10);
=======


    read_temperature_sensor_CMockExpectAndReturn(22, -10);
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

<<<<<<< HEAD
   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);
=======
   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

}



void test_check_temperature_should_return_0_when_normal(void) {

<<<<<<< HEAD
    read_temperature_sensor_CMockExpectAndReturn(25, 25);
=======


    read_temperature_sensor_CMockExpectAndReturn(28, 22);
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

<<<<<<< HEAD
   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_INT);
=======
   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

}





<<<<<<< HEAD


void test_check_temperature_should_handle_exact_limits(void) {

    read_temperature_sensor_CMockExpectAndReturn(32, 15);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);



    read_temperature_sensor_CMockExpectAndReturn(35, 30);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (
=======
void test_check_temperature_should_handle_exact_limits(void) {



    read_temperature_sensor_CMockExpectAndReturn(35, -40);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((check_temperature())), (
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);





<<<<<<< HEAD
}



void test_check_temperature_should_handle_sensor_failure(void) {

    read_temperature_sensor_CMockExpectAndReturn(42, -41);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);



    read_temperature_sensor_CMockExpectAndReturn(45, 126);
=======
    read_temperature_sensor_CMockExpectAndReturn(39, 125);
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

<<<<<<< HEAD
   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);
=======
   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

}





void test_check_temperature_should_handle_sensor_failure(void) {



    read_temperature_sensor_CMockExpectAndReturn(46, -999);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

}
