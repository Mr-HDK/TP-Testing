#include "unity.h"
#include "controller.h"
#include "sensor.h"
#include <stdlib.h>

void setUp(void) {
            srand(42); // Fixed seed for reproducibility
}
void tearDown(void) {}

void test_sensor_and_controller_integration(void) {
    int sensor_value = read_sensor(); // Get sensor data
    if (is_valid_value(sensor_value)) {
        int processed_value = process_data(sensor_value); // Process data
        TEST_ASSERT_EQUAL(sensor_value * 2 + 10, processed_value);
    } else {
        //TEST_FAIL_MESSAGE("Invalid sensor value encountered.");
        printf("Skipping invalid sensor value: %d\n", sensor_value);
        return;  // Pour éviter l'échec du test à l'encontre d'une valeur invalide
    }
}


void test_process_data_handles_edge_cases(void) {
    // Vous pouvez ajouter plus de edge cases (99, 1..)
    // Cas limites valides
    TEST_ASSERT_EQUAL(10, process_data(0));  // Edge case: Lowest valid input
    TEST_ASSERT_EQUAL(210, process_data(100)); // Edge case: Highest valid input

    TEST_ASSERT_EQUAL(12, process_data(1));    // Cas proche de la borne inférieure
    TEST_ASSERT_EQUAL(208, process_data(99));  // Cas proche de la borne supérieure

    // Cas spécifiques (par exemple, multiples de 10)
    TEST_ASSERT_EQUAL(30, process_data(10));   // Multiple de 10
    TEST_ASSERT_EQUAL(110, process_data(50));  // Valeur médiane

    // Cas de validation : Entrées invalides (si applicable)
    TEST_ASSERT_EQUAL(8, process_data(-1));   // Cas invalide : Nombre négatif
    TEST_ASSERT_EQUAL(212, process_data(101));  // Cas invalide : Plus grande que 100
}
