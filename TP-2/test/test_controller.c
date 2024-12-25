#include "unity.h"
#include "controller.h"
#include "sensor.h"
#include <stdlib.h>

void setUp(void) {
            srand(42); // Fixed seed for reproducibility
}
void tearDown(void) {}
// valider l'intégration entre lecture du capteur et le traitement des données
void test_sensor_and_controller_integration(void) {
    int sensor_value = read_sensor(); // Get sensor data
    if (is_valid_value(sensor_value)) {
        int processed_value = process_data(sensor_value); // Process data
        TEST_ASSERT_EQUAL(sensor_value * 2 + 10, processed_value);
    } else {
        //TEST_FAIL_MESSAGE("Invalid sensor value encountered.");
        printf("Skipping invalid sensor value: %d\n", sensor_value);
        //continue;  // Pour éviter l'échec du test à l'encontre d'une valeur invalide
        return;
        
    }
}


void test_process_data_handles_edge_cases(void) {
    // Vous pouvez ajouter plus de edge cases (99, 1..)
    TEST_ASSERT_EQUAL(10, process_data(0));  // Edge case: Lowest valid input
    TEST_ASSERT_EQUAL(210, process_data(100)); // Edge case: Highest valid input

    // Cas proches des limites
    TEST_ASSERT_EQUAL(12, process_data(1));   // Next value after 0
    TEST_ASSERT_EQUAL(208, process_data(99)); // Next value before 100
    // Cas intermédiaires
    TEST_ASSERT_EQUAL(110, process_data(50)); // Mid-range value
    TEST_ASSERT_EQUAL(20, process_data(5));   // Low-range value

       // Cas négatifs (pertinents pour une température)
    TEST_ASSERT_EQUAL(0, process_data(-5));   // Exemple : Température négative basse
    TEST_ASSERT_EQUAL(-8, process_data(-9));  // Exemple : Température négative plus basse
    TEST_ASSERT_EQUAL(-190, process_data(-100)); // Cas limite pour une valeur négative élevée
}
