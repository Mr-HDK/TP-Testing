#include "src/sensor.h"
#include "src/controller.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {}

void tearDown(void) {}



void test_sensor_and_controller_integration(void) {

    int sensor_value = read_sensor();

    printf("Sensor Value: %d\n", sensor_value);

    if (is_valid_value(sensor_value)) {

        int processed_value = process_data(sensor_value);

        UnityAssertEqualNumber((UNITY_INT)((sensor_value * 2 + 10)), (UNITY_INT)((processed_value)), (

       ((void *)0)

       ), (UNITY_UINT)(13), UNITY_DISPLAY_STYLE_INT);

    } else {

        UnityFail( (("Invalid sensor value encountered.")), (UNITY_UINT)(15));

    }

}





void test_process_data_handles_edge_cases(void) {

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((process_data(0))), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((210)), (UNITY_INT)((process_data(100))), (

   ((void *)0)

   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);

}
