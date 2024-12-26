#include "unity.h"
#include "temp_controller.h"
#include "mock_temp_sensor.h"

void setUp(void) {
<<<<<<< HEAD
    mock_temp_sensor_Init();
}

void tearDown(void) {
    mock_temp_sensor_Verify();
    mock_temp_sensor_Destroy();
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
=======
    mock_temp_sensor_Init();  // Initialisation des mocks
}

void tearDown(void) {
    mock_temp_sensor_Verify(); // Vérification des mocks
    mock_temp_sensor_Destroy(); // Nettoyage des mocks
}

void test_check_temperature_should_return_1_when_too_hot(void) {
    // Mock de la lecture du capteur avec une température élevée
    read_temperature_sensor_ExpectAndReturn(35); // Température élevée
    TEST_ASSERT_EQUAL(1, check_temperature()); // Résultat attendu : 1
}

void test_check_temperature_should_return_minus_1_when_too_cold(void) {
    // Mock de la lecture du capteur avec une température basse
    read_temperature_sensor_ExpectAndReturn(-10); // Température basse
    TEST_ASSERT_EQUAL(-1, check_temperature()); // Résultat attendu : -1
}

void test_check_temperature_should_return_0_when_normal(void) {
    // Mock de la lecture du capteur avec une température normale
    read_temperature_sensor_ExpectAndReturn(22); // Température normale
    TEST_ASSERT_EQUAL(0, check_temperature()); // Résultat attendu : 0
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e
}

// Test des limites exactes
void test_check_temperature_should_handle_exact_limits(void) {
<<<<<<< HEAD
    read_temperature_sensor_ExpectAndReturn(15); // Limite basse
    TEST_ASSERT_EQUAL(0, check_temperature());

    read_temperature_sensor_ExpectAndReturn(30); // Limite haute
    TEST_ASSERT_EQUAL(0, check_temperature());

    /* ++ Vous pouvez ajouter d'autres tests pour explorer les limites ++ */
}

void test_check_temperature_should_handle_sensor_failure(void) {
    read_temperature_sensor_ExpectAndReturn(-41); // Température hors limite basse
    TEST_ASSERT_EQUAL(-1, check_temperature());

    read_temperature_sensor_ExpectAndReturn(126); // Température hors limite haute
    TEST_ASSERT_EQUAL(1, check_temperature());
}


/* 
    ++ Bonus : Ajoutez un test pour gérer un échec du capteur ++
Écrivez un test pour simuler un comportement lorsque la température dépasse 125° ou descend sous -40° (valeurs hors normes "hardware limits"). 
    - Étape 1 : Modifiez la fonction 'check_temperature' dans '/src/temp_controller.c' pour gérer ces cas.
    - Étape 2 : Créez un test unitaire pour valider ce comportement.
*/
=======
    // Limite basse (température trop basse)
    read_temperature_sensor_ExpectAndReturn(-40); // Limite basse
    TEST_ASSERT_EQUAL(-1, check_temperature()); // Résultat attendu : -1

    // Limite haute (température trop haute)
    read_temperature_sensor_ExpectAndReturn(125); // Limite haute
    TEST_ASSERT_EQUAL(1, check_temperature()); // Résultat attendu : 1
}

// Bonus : Test pour un échec du capteur
void test_check_temperature_should_handle_sensor_failure(void) {
    // Cas où le capteur échoue en retournant une valeur impossible (-999 par exemple)
    read_temperature_sensor_ExpectAndReturn(-999); // Valeur invalide pour échec
    TEST_ASSERT_EQUAL(-1, check_temperature()); // Résultat attendu : -1 (ou une autre valeur spécifique indiquant un échec)
}
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e
