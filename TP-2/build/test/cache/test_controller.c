#include "src/sensor.h"
#include "src/controller.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void) {

            srand(42);

}

void tearDown(void) {}



void test_sensor_and_controller_integration(void) {

    int sensor_value = read_sensor();

    if (is_valid_value(sensor_value)) {

        int processed_value = process_data(sensor_value);

        UnityAssertEqualNumber((UNITY_INT)((sensor_value * 2 + 10)), (UNITY_INT)((processed_value)), (

       ((void *)0)

       ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);

    } else {



        printf("Skipping invalid sensor value: %d\n", sensor_value);



        return;

    }

}







void test_process_data_handles_edge_cases(void) {



    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((process_data(0))), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((210)), (UNITY_INT)((process_data(100))), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

}
