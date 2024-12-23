#include "src/utils.h"
#include "src/notifier.h"
#include "src/controller.h"
#include "src/sensor.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {}

void tearDown(void) {}



void test_valid_sensor_value_workflow(void) {

    int simulated_sensor_value = 50;

    int expected_processed_value = simulated_sensor_value * 2 + 10;





    set_sensor_value(simulated_sensor_value);





    int sensor_value = read_sensor();





    if (is_value_valid(sensor_value)) {



        int processed_value = process_data(sensor_value);





        save_data(processed_value);





        UnityAssertEqualNumber((UNITY_INT)((simulated_sensor_value)), (UNITY_INT)((sensor_value)), (

       ((void *)0)

       ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

        UnityAssertEqualNumber((UNITY_INT)((expected_processed_value)), (UNITY_INT)((processed_value)), (

       ((void *)0)

       ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

    } else {

        UnityFail( (("La valeur du capteur devrait tre valide mais ne l'est pas.")), (UNITY_UINT)(32));

    }

}



void test_invalid_sensor_value_workflow(void) {

    int simulated_invalid_value = 120;





    set_sensor_value(simulated_invalid_value);





    int sensor_value = read_sensor();





    if (!is_value_valid(sensor_value)) {



        send_notification("Valeur capteur invalide dtecte");





        UnityAssertEqualNumber((UNITY_INT)((simulated_invalid_value)), (UNITY_INT)((sensor_value)), (

       ((void *)0)

       ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

    } else {

        UnityFail( (("La valeur du capteur devrait tre invalide mais ne l'est pas.")), (UNITY_UINT)(53));

    }

}



void test_boundary_conditions(void) {

    int boundary_values[] = {0, 100, -1, 101};



    for (int i = 0; i < sizeof(boundary_values) / sizeof(boundary_values[0]); i++) {

        int value = boundary_values[i];





        set_sensor_value(value);





        int sensor_value = read_sensor();





        if (is_value_valid(sensor_value)) {

            int processed_value = process_data(sensor_value);

            save_data(processed_value);





            UnityAssertEqualNumber((UNITY_INT)((value)), (UNITY_INT)((sensor_value)), (

           ((void *)0)

           ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT);

        } else {

            send_notification("Valeur capteur hors limites");





            UnityAssertEqualNumber((UNITY_INT)((value)), (UNITY_INT)((sensor_value)), (

           ((void *)0)

           ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

        }

    }

}
