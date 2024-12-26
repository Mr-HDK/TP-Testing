#include "build/test/mocks/mock_sensor.h"
#include "src/utils.h"
#include "src/notifier.h"
#include "src/controller.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {

    mock_sensor_Init();

}



void tearDown(void) {

    mock_sensor_Destroy();

}











void test_valid_sensor_value_workflow(void) {

    int simulated_sensor_value = 50;

    int expected_processed_value = simulated_sensor_value * 2 + 10;



    read_sensor_CMockExpectAndReturn(24, simulated_sensor_value);



    int sensor_value = read_sensor();

    do {if ((sensor_value >= 0 && sensor_value < 150)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(27)));}} while(0);



    if (is_valid_value(sensor_value)) {

        int processed_value = process_data(sensor_value);



        log_data(processed_value);

        UnityAssertEqualNumber((UNITY_INT)((expected_processed_value)), (UNITY_INT)((processed_value)), (

       ((void *)0)

       ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

    } else {

        UnityFail( (("Sensor value should be valid for this test")), (UNITY_UINT)(35));

    }

}











void test_invalid_sensor_value_workflow(void) {

    int simulated_invalid_value = 120;



    read_sensor_CMockExpectAndReturn(46, simulated_invalid_value);

    int sensor_value = read_sensor();



    if (!is_valid_value(sensor_value)) {

        notify_threshold_exceeded(sensor_value);

        do {if (!(is_valid_value(sensor_value))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(51)));}} while(0);

    } else {

        UnityFail( (("Expected invalid sensor value for this test")), (UNITY_UINT)(53));

    }

}











void test_boundary_conditions(void) {

    int boundary_values[] = {0, 100, -1, 101};



    for (int i = 0; i < sizeof(boundary_values) / sizeof(boundary_values[0]); i++) {

        int value = boundary_values[i];

        read_sensor_CMockExpectAndReturn(66, value);

        int sensor_value = read_sensor();



        if (is_valid_value(sensor_value)) {

            int processed_value = process_data(sensor_value);

            log_data(processed_value);

            UnityAssertEqualNumber((UNITY_INT)((sensor_value * 2 + 10)), (UNITY_INT)((processed_value)), (

           ((void *)0)

           ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);

            do {if ((sensor_value == 0 || sensor_value == 100)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(73)));}} while(0);

        } else {

            notify_threshold_exceeded(sensor_value);

            do {if ((sensor_value == -1 || sensor_value == 101)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(76)));}} while(0);

        }

    }

}





void test_complete_processing_chain(void) {



    for (int i = 0; i < 10; i++) {

        int test_value = 50 + i;

        read_sensor_CMockExpectAndReturn(86, test_value);



        int sensor_value = read_sensor();



        if (is_valid_value(sensor_value)) {

            int processed_value = process_data(sensor_value);

            log_data(processed_value);





            UnityAssertEqualNumber((UNITY_INT)((sensor_value * 2 + 10)), (UNITY_INT)((processed_value)), (

           ((void *)0)

           ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_INT);

            do {if ((sensor_value >= 0 && sensor_value <= 100)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(96)));}} while(0);

        } else {

            notify_threshold_exceeded(sensor_value);

            do {if ((sensor_value < 0 || sensor_value > 100)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(99)));}} while(0);

        }

    }

}
