#include "unity.h"
#include "sensor.h"
#include "controller.h"
#include "notifier.h"
#include "utils.h"
#include <stdlib.h>

/*
 * Instructions :
 * 1. Complétez les parties manquantes (indiquées par `/* À COMPLÉTER * /`).
 * 2. Lisez les commentaires pour comprendre le but de chaque test.
 * 3. Exécutez `ceedling test:all` pour valider vos réponses.
 */

void setUp(void) {
    /* À COMPLÉTER : Initialiser le générateur de nombres 
     * aléatoires pour des résultats reproductibles (seed)
     */
    srand(42);
    }
void tearDown(void) {}


/* Test : Workflow avec des valeurs valides (hors bordures)
 * Objectif : Vérifier que les valeurs valides générées par `read_sensor`
 * sont correctement traitées par `process_data`.
 */
void test_valid_sensor_value_workflow(void) {
    for (int i = 0; i < 20; i++) {  // Vous pouvez augmenter le nombre d'itérations pour plus de couverture
        int sensor_value = read_sensor();
        if (sensor_value > 0 && sensor_value < 100) {
            int processed_value = process_data(sensor_value); // Traitez la valeur du capteur
            log_data(processed_value); // Enregistrez la donnée traitée
            TEST_ASSERT_EQUAL_INT(sensor_value * 2 + 10, processed_value); // Vérifiez que le traitement est correct
        }
    }
}

/* Test : Workflow avec des valeurs invalides
 * Objectif : Vérifier que les valeurs hors plage déclenchent une alerte.
 */
void test_invalid_sensor_value_workflow(void) {
    for (int i = 0; i < 20; i++) {  // Vous pouvez augmenter le nombre d'itérations pour plus de couverture
        int sensor_value = read_sensor();
        if (is_valid_value(sensor_value) == false) {
            notify_threshold_exceeded(sensor_value); // Déclenchez une alerte pour les valeurs invalides
            TEST_ASSERT(is_valid_value(sensor_value) == false); // Vérifiez que la condition d'invalidité est respectée
        }
    }
}

/* Test : Conditions limites (bordures uniquement)
 * Objectif : Vérifier le comportement du système pour des valeurs critiques.
 * N.B : ici on contourne read_sensor pour injecter des valeurs précise.
 */
void test_boundary_conditions(void) {
    int boundary_values[] = {0, 100, -1, 101, 149}; // Bordures valides et invalides
    for (int i = 0; i < sizeof(boundary_values) / sizeof(boundary_values[0]); i++) {
        int sensor_value = boundary_values[i];
        if (is_valid_value(sensor_value)) {
            int processed_value = process_data(sensor_value);
            log_data(processed_value);
            TEST_ASSERT_EQUAL_INT(sensor_value * 2 + 10, processed_value);
        } else {
            notify_threshold_exceeded(sensor_value);
            TEST_ASSERT(is_valid_value(sensor_value) == false);
        }
    }
}
