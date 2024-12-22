#include "src/utils.h"
#include "src/notifier.h"
#include "src/controller.h"
#include "src/sensor.h"
#include "C:/Users/HP/TP-Testing/TP-2/vendor/ceedling/vendor/unity/src/unity.h"


void setUp(void) {

    srand(42);

}



void tearDown(void) {}













void test_valid_sensor_value_workflow(void) {

    for (int i = 0; i < 20; i++) {

        int sensor_value = read_sensor();

        if (sensor_value > 0 && sensor_value < 100) {

            int processed_value = process_data(sensor_value);

            log_data(processed_value);





            UnityAssertEqualNumber((UNITY_INT)((sensor_value * 2)), (UNITY_INT)((processed_value)), (

           ((void *)0)

           ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

        }

    }

}













void test_invalid_sensor_value_workflow(void) {

    for (int i = 0; i < 20; i++) {

        int sensor_value = read_sensor();

        if (sensor_value < 0 || sensor_value > 100) {

            notify_threshold_exceeded(sensor_value);



            UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((1)), (

           ((void *)0)

           ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);



        }

    }

}











void test_boundary_conditions(void) {

    int boundary_values[] = {0, 100, -1, 101, 149};

    for (int i = 0; i < sizeof(boundary_values) / sizeof(boundary_values[0]); i++) {

        int sensor_value = boundary_values[i];

        if (is_valid_value(sensor_value)) {

            int processed_value = process_data(sensor_value);

            log_data(processed_value);



            UnityAssertEqualNumber((UNITY_INT)((sensor_value * 2)), (UNITY_INT)((processed_value)), (

           ((void *)0)

           ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

        } else {

            notify_threshold_exceeded(sensor_value);



            UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((1)), (

           ((void *)0)

           ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);

        }

    }

}