#include "src/utils.h"
#include "src/notifier.h"
#include "src/controller.h"
#include "src/sensor.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {







      srand(42);

    }

void tearDown(void) {}













void test_valid_sensor_value_workflow(void) {

    for (int i = 0; i < 20; i++) {

        int sensor_value = rand() % 99 + 1;

        if (sensor_value > 0 && sensor_value < 100) {

            int processed_value = process_data(sensor_value);

            log_data(processed_value);

            UnityAssertEqualNumber((UNITY_INT)((sensor_value * 2 + 10)), (UNITY_INT)((processed_value)), (

           ((void *)0)

           ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

        }

    }

}









void test_invalid_sensor_value_workflow(void) {

    for (int i = 0; i < 20; i++) {

        int sensor_value = rand() % 200 - 50;

        if (sensor_value <= 0 || sensor_value >= 100) {

            notify_threshold_exceeded(sensor_value);

            do {if ((sensor_value <= 0 || sensor_value >= 100)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(47)));}} while(0);

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

            UnityAssertEqualNumber((UNITY_INT)((sensor_value * 2 + 10)), (UNITY_INT)((processed_value)), (

           ((void *)0)

           ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

        } else {

            notify_threshold_exceeded(sensor_value);

            do {if ((sensor_value <= 0 || sensor_value >= 100)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(66)));}} while(0);

        }

    }

}
