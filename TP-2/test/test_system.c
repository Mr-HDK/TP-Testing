#include "unity.h"
#include "sensor.h"
#include "controller.h"
#include "notifier.h"
#include "utils.h"

/*
 * Instructions :
 * Complétez les sections marquées par `// À compléter`.
 * - Testez les interactions entre les modules `sensor`, `controller`, `notifier`, et `utils`.
 * - Suivez les étapes et utilisez les commentaires comme guide.
 */

void setUp(void) {}
void tearDown(void) {}

/*
 * Test : Workflow avec une valeur capteur valide
 * Objectif : Valider le traitement complet des données valides.
 */
void test_valid_sensor_value_workflow(void) {
    int simulated_sensor_value = 50;  // Valeur simulée
    int expected_processed_value = simulated_sensor_value * 2 + 10;

    // Étape 1 : Simuler une température dans le capteur
    // À compléter : Utilisez une fonction pour définir la température simulée.
    // Indice : Regardez les fonctions disponibles dans `sensor.h`.

    int sensor_value = read_sensor();

    // Étape 2 : Vérifier si la valeur est valide
    // À compléter : Utilisez une fonction pour valider la valeur du capteur.
    if ( /* À compléter : Condition pour vérifier la validité */ ) {
        // Étape 3 : Traiter la valeur
        int processed_value = process_data(sensor_value);

        // Étape 4 : Enregistrer la valeur traitée
        // À compléter : Appelez une fonction pour enregistrer les données.
    }

    // Vérifications
    // À compléter : Ajoutez des assertions pour vérifier que `sensor_value` et `processed_value` sont corrects.
}

/*
 * Test : Workflow avec une valeur capteur invalide
 * Objectif : Valider le comportement en cas de dépassement de seuil.
 */
void test_invalid_sensor_value_workflow(void) {
    int simulated_invalid_value = 120;  // Valeur simulée invalide

    // Étape 1 : Simuler une température invalide
    // À compléter : Définissez la température simulée.

    int sensor_value = read_sensor();

    // Étape 2 : Vérifier si la valeur est invalide
    if ( /* À compléter : Condition pour vérifier l'invalidité */ ) {
        // Étape 3 : Notifier le dépassement de seuil
        // À compléter : Appelez une fonction pour envoyer une notification.
    }

    // Vérifications
    // À compléter : Ajoutez une assertion pour vérifier que `sensor_value` est invalide.
}

/*
 * Test : Conditions limites
 * Objectif : Tester les valeurs limites.
 */
void test_boundary_conditions(void) {
    int boundary_values[] = {0, 100, -1, 101};

    for (int i = 0; i < sizeof(boundary_values) / sizeof(boundary_values[0]); i++) {
        int value = boundary_values[i];

        // Étape 1 : Simuler une valeur limite
        // À compléter : Définissez la valeur limite.

        int sensor_value = read_sensor();

        // Étape 2 : Vérifiez si la valeur est valide ou invalide
        if ( /* À compléter : Condition pour valider/invalider */ ) {
            // Étape 3 : Traiter ou notifier selon le cas
            // À compléter : Traitez la valeur ou notifiez le dépassement de seuil.
        }

        // Vérifications
        // À compléter : Ajoutez des assertions pour vérifier le comportement attendu.
    }
}
