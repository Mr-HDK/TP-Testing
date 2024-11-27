#include "unity.h"
#include "temp_controller.h"
#include "mock_temp_sensor.h"

void setUp(void) {
    // Initialisez les mocks (optionnel, car CMock gère souvent cela automatiquement)
    mock_temp_sensor_Init();
}

void tearDown(void) {
    // Nettoyez les mocks pour libérer la mémoire ou réinitialiser l'état
    mock_temp_sensor_Verify(); // Vérifie que toutes les fonctions attendues ont été appelées
    mock_temp_sensor_Destroy(); // Réinitialise l'état interne des mocks
}

void test_check_temperature_should_return_1_when_too_hot(void) {
    read_temperature_sensor_ExpectAndReturn(45);
    TEST_ASSERT_EQUAL(1, check_temperature());
}

void test_check_temperature_should_return_minus_1_when_too_cold(void) {
    read_temperature_sensor_ExpectAndReturn(14);
    TEST_ASSERT_EQUAL(-1, check_temperature());
}

void test_check_temperature_should_return_0_when_normal(void) {
    read_temperature_sensor_ExpectAndReturn(20);
    TEST_ASSERT_EQUAL(0, check_temperature());
}


// Testes supplémentaires : Cas limites exacts
void test_check_temperature_should_handle_exact_limits(void) {
    read_temperature_sensor_ExpectAndReturn(40); // Limite basse
    TEST_ASSERT_EQUAL(1, check_temperature());

    read_temperature_sensor_ExpectAndReturn(10); // Limite haute
    TEST_ASSERT_EQUAL(-1, check_temperature());

    /* ++ Vous pouvez ajouter d'autres tests pour explorer les limites ++ */
}


/* 
    ++ Bonus : Ajoutez un test pour gérer un échec du capteur ++
Écrivez un test pour simuler un comportement lorsque la température dépasse 125° ou descend sous -40° (valeurs hors normes "hardware limits"). 
    - Étape 1 : Modifiez la fonction 'check_temperature' dans '/src/temp_controller.c' pour gérer ces cas.
    - Étape 2 : Créez un test unitaire pour valider ce comportement.
*/

