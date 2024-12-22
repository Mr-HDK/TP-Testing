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
    srand(42);  // Utilisation d'un "seed" fixe pour garantir la reproductibilité des tests
}

void tearDown(void) {}


/* Test : Workflow avec des valeurs valides (hors bordures)
 * Objectif : Vérifier que les valeurs valides générées par `read_sensor`
 * sont correctement traitées par `process_data`.
 */
void test_valid_sensor_value_workflow(void) {
    for (int i = 0; i < 20; i++) {  // Augmenter le nombre d'itérations pour plus de couverture
        int sensor_value = read_sensor();  // Lecture d'une valeur aléatoire du capteur
        if (sensor_value > 0 && sensor_value < 100) {  // On ne traite que les valeurs valides
            int processed_value = process_data(sensor_value);  // Traitement de la donnée
            log_data(processed_value);  // Enregistrement de la donnée traitée
            // Vérification que la valeur traitée correspond à un traitement attendu
            // (ici, il faut remplacer `processed_value = sensor_value * 2` par l'équation réelle de traitement)
            TEST_ASSERT_EQUAL_INT(sensor_value * 2, processed_value);  // Exemple d'une transformation simple
        }
    }
}


/* Test : Workflow avec des valeurs invalides
 * Objectif : Vérifier que les valeurs hors plage déclenchent une alerte.
 */

void test_invalid_sensor_value_workflow(void) {
    for (int i = 0; i < 20; i++) {
        int sensor_value = read_sensor();  // Lecture d'une valeur aléatoire du capteur
        if (sensor_value < 0 || sensor_value > 100) {  // Valeurs invalides
            notify_threshold_exceeded(sensor_value);  // Déclenchement de l'alerte
            // Vérification que l'alerte est bien déclenchée (cela dépend de l'implémentation)
            TEST_ASSERT_EQUAL_INT(1, 1);  // Ici, il est nécessaire de vérifier un comportement réel
            // Par exemple, si vous avez une variable d'état ou un mock pour `notify_threshold_exceeded`
        }
    }
}

/* Test : Conditions limites (bordures uniquement)
 * Objectif : Vérifier le comportement du système pour des valeurs critiques.
 * N.B : ici on contourne read_sensor pour injecter des valeurs précise.
 */
void test_boundary_conditions(void) {
    int boundary_values[] = {0, 100, -1, 101, 149};  // Valeurs aux bords et hors bords
    for (int i = 0; i < sizeof(boundary_values) / sizeof(boundary_values[0]); i++) {
        int sensor_value = boundary_values[i];  // Injection d'une valeur parmi les bords
        if (is_valid_value(sensor_value)) {  // Vérifier si la valeur est valide
            int processed_value = process_data(sensor_value);  // Traitement de la donnée
            log_data(processed_value);  // Enregistrement de la donnée traitée
            // Vérification du traitement. Remplacer par l'équation réelle de votre fonction
            TEST_ASSERT_EQUAL_INT(sensor_value * 2, processed_value);  // Exemple de traitement (à ajuster)
        } else {
            notify_threshold_exceeded(sensor_value);  // Si la valeur est invalide, alerte
            // Vérification que l'alerte est bien déclenchée
            TEST_ASSERT_EQUAL_INT(1, 1);  // Vérification basique, à ajuster selon la gestion d'alertes
        }
    }
}

