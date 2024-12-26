#include "unity.h"
#include "sensor.h"
#include "controller.h"
#include "notifier.h"
#include "utils.h"
#include "mock_sensor.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void) {
    mock_sensor_Init();
}

void tearDown(void) {
    mock_sensor_Destroy();
}

/*
 * Test : Workflow avec une valeur capteur valide
 * Objectif : Valider le traitement complet des données valides.
 */
void test_valid_sensor_value_workflow(void) {
    int simulated_sensor_value = 50;  // Valeur simulée
    int expected_processed_value = simulated_sensor_value * 2 + 10;

    read_sensor_ExpectAndReturn(simulated_sensor_value);

    int sensor_value = read_sensor();
    TEST_ASSERT(sensor_value >= 0 && sensor_value < 150);

    if (is_valid_value(sensor_value)) {
        int processed_value = process_data(sensor_value);

        log_data(processed_value);
        TEST_ASSERT_EQUAL(expected_processed_value, processed_value);
    } else {
        TEST_FAIL_MESSAGE("Sensor value should be valid for this test");
    }
}

/*
 * Test : Workflow avec une valeur capteur invalide
 * Objectif : Valider le comportement en cas de dépassement de seuil.
 */
void test_invalid_sensor_value_workflow(void) {
    int simulated_invalid_value = 120;  // Valeur simulée invalide

    read_sensor_ExpectAndReturn(simulated_invalid_value);
    int sensor_value = read_sensor();

    if (!is_valid_value(sensor_value)) {
        notify_threshold_exceeded(sensor_value);
        TEST_ASSERT_FALSE(is_valid_value(sensor_value));
    } else {
        TEST_FAIL_MESSAGE("Expected invalid sensor value for this test");
    }
}

/*
 * Test : Conditions limites
 * Objectif : Tester les valeurs limites.
 */
void test_boundary_conditions(void) {
    int boundary_values[] = {0, 100, -1, 101};

    for (int i = 0; i < sizeof(boundary_values) / sizeof(boundary_values[0]); i++) {
        int value = boundary_values[i];
        read_sensor_ExpectAndReturn(value);
        int sensor_value = read_sensor();

        if (is_valid_value(sensor_value)) {
            int processed_value = process_data(sensor_value);
            log_data(processed_value);
            TEST_ASSERT_EQUAL(sensor_value * 2 + 10, processed_value);
            TEST_ASSERT(sensor_value == 0 || sensor_value == 100);
        } else {
            notify_threshold_exceeded(sensor_value);
            TEST_ASSERT(sensor_value == -1 || sensor_value == 101);
        }
    }
}

// Nouveau test pour vérifier la chaîne complète de traitement
void test_complete_processing_chain(void) {
    // Test avec plusieurs valeurs
    for (int i = 0; i < 10; i++) {
        int test_value = 50 + i;
        read_sensor_ExpectAndReturn(test_value);

        int sensor_value = read_sensor();

        if (is_valid_value(sensor_value)) {
            int processed_value = process_data(sensor_value);
            log_data(processed_value);

            // Vérifications
            TEST_ASSERT_EQUAL(sensor_value * 2 + 10, processed_value);
            TEST_ASSERT(sensor_value >= 0 && sensor_value <= 100);
        } else {
            notify_threshold_exceeded(sensor_value);
            TEST_ASSERT(sensor_value < 0 || sensor_value > 100);
        }
    }
}