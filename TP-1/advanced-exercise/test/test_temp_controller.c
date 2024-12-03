#include "unity.h"
#include "temp_controller.h"
#include "mock_temp_sensor.h"

void setUp(void) {
    // Initialisez les mocks "Bonne pratique"
    // ??
}

void tearDown(void) {
    // Nettoiez les mocks "Bonne pratique"
    // ??
}

void test_check_temperature_should_return_1_when_too_hot(void) {
    read_temperature_sensor_ExpectAndReturn(35);
    TEST_ASSERT_EQUAL(1, check_temperature());
}

void test_check_temperature_should_return_minus_1_when_too_cold(void) {
    read_temperature_sensor_ExpectAndReturn(10);
    TEST_ASSERT_EQUAL(-1, check_temperature());
}

void test_check_temperature_should_return_0_when_normal(void) {
    read_temperature_sensor_ExpectAndReturn(25);
    TEST_ASSERT_EQUAL(0, check_temperature());
}


// Testes supplémentaires : Cas limites exacts
void test_check_temperature_should_handle_exact_limits(void) {
    read_temperature_sensor_ExpectAndReturn(15); // Limite basse
    TEST_ASSERT_EQUAL(0, check_temperature());

    read_temperature_sensor_ExpectAndReturn(30); // Limite haute
    TEST_ASSERT_EQUAL(0, check_temperature());

    /* ++ Vous pouvez ajouter d'autres tests pour explorer les limites ++ */
}

void test_check_temperature_should_handle_sensor_failure(void) {
    read_temperature_sensor_ExpectAndReturn(-41); // Température hors limite basse
    TEST_ASSERT_EQUAL(-2, check_temperature());

    read_temperature_sensor_ExpectAndReturn(126); // Température hors limite haute
    TEST_ASSERT_EQUAL(-2, check_temperature());
}


/* 
    ++ Bonus : Ajoutez un test pour gérer un échec du capteur ++
Écrivez un test pour simuler un comportement lorsque la température dépasse 125° ou descend sous -40° (valeurs hors normes "hardware limits"). 
    - Étape 1 : Modifiez la fonction 'check_temperature' dans '/src/temp_controller.c' pour gérer ces cas.
    - Étape 2 : Créez un test unitaire pour valider ce comportement.
*/

