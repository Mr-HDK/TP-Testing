#include "unity.h"
#include "temp_controller.h"
#include "mock_temp_sensor.h"

void setUp(void) {
    // Initialisez les mocks avant chaque test
    mock_temp_sensor_Init();
}

void tearDown(void) {
    // Nettoyez les mocks après chaque test
    mock_temp_sensor_Destroy();
}

void test_check_temperature_should_return_1_when_too_hot(void) {
    // Simule une température élevée
    read_temperature_sensor_ExpectAndReturn(85); // Exemple : au-dessus du seuil "hot"
    TEST_ASSERT_EQUAL(1, check_temperature());
}

void test_check_temperature_should_return_minus_1_when_too_cold(void) {
    // Simule une température basse
    read_temperature_sensor_ExpectAndReturn(-5); // Exemple : en dessous du seuil "cold"
    TEST_ASSERT_EQUAL(-1, check_temperature());
}

void test_check_temperature_should_return_0_when_normal(void) {
    // Simule une température normale
    read_temperature_sensor_ExpectAndReturn(25); // Exemple : dans la plage normale
    TEST_ASSERT_EQUAL(0, check_temperature());
}

void test_check_temperature_should_handle_exact_limits(void) {
    // Teste la limite basse exacte
    read_temperature_sensor_ExpectAndReturn(0); // Exemple : seuil bas
    TEST_ASSERT_EQUAL(0, check_temperature());

    // Teste la limite haute exacte
    read_temperature_sensor_ExpectAndReturn(80); // Exemple : seuil haut
    TEST_ASSERT_EQUAL(0, check_temperature());
}

void test_check_temperature_should_handle_sensor_failure(void) {
    // Simule une défaillance matérielle (hors plage matérielle)
    read_temperature_sensor_ExpectAndReturn(130); // Exemple : au-dessus de 125° (hardware limit)
    TEST_ASSERT_EQUAL(-2, check_temperature());

    read_temperature_sensor_ExpectAndReturn(-50); // Exemple : en dessous de -40° (hardware limit)
    TEST_ASSERT_EQUAL(-2, check_temperature());
}
