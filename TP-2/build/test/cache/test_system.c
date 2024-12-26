#include "src/utils.h"
#include "src/notifier.h"
#include "src/controller.h"
#include "src/sensor.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
void setUp(void) {}

void tearDown(void) {}













void test_valid_sensor_value_workflow(void) {

    int processed_value = 0;

    int simulated_sensor_value = 30;

    int expected_processed_value = simulated_sensor_value * 2 + 10;











    int sensor_value = simulated_sensor_value;





    

   _Bool 

        is_valid= is_valid_value(sensor_value);

    do {if ((is_valid)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(35)));}} while(0);





    if ( is_valid) {



        processed_value = process_data(sensor_value);







        log_data(processed_value);

    }

    UnityAssertEqualNumber((UNITY_INT)((expected_processed_value)), (UNITY_INT)((processed_value)), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);





}

void test_invalid_sensor_value_workflow(void) {

    int simulated_invalid_value = 120;



    int expected_processed_value = simulated_invalid_value * 2 + 10;

    int processed_value = 0;











    int sensor_value = simulated_invalid_value;





    if ( !is_valid_value(sensor_value ) ) {





        notify_threshold_exceeded(sensor_value);

    }







    do {if (((sensor_value * 2 + 10) != (processed_value))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(80)));}} while(0);

}

void test_boundary_conditions(void) {

    int boundary_values[] = {0, 100, -1, 101};

    int processed_value=0;



    for (int i = 0; i < sizeof(boundary_values) / sizeof(boundary_values[0]); i++) {

        int value = boundary_values[i];









        int sensor_value = value;

        

       _Bool 

            is_valid= is_valid_value(sensor_value);





        if ( is_valid ) {





            processed_value = process_data(sensor_value);

            log_data(processed_value);

            UnityAssertEqualNumber((UNITY_INT)((sensor_value * 2 + 10)), (UNITY_INT)((processed_value)), (

           ((void *)0)

           ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);



        } else {







        notify_threshold_exceeded(sensor_value);





        do {if (((sensor_value * 2 + 10) != (processed_value))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(121)));}} while(0);

        }

        do {if ((is_valid || !is_valid)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(123)));}} while(0);



    }

}
