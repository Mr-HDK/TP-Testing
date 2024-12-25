#include "unity.h"
#include "temp_controller.h"
#include "mock_temp_sensor.h"

void setUp(void) {
    mock_temp_sensor_Init();
}

void tearDown(void) {
    mock_temp_sensor_Destroy();
}

void test_check_temperature_should_return_1_when_too_hot(void) {
    read_temperature_sensor_ExpectAndReturn(100);
    TEST_ASSERT_EQUAL(1, check_temperature());
}

void test_check_temperature_should_return_minus_1_when_too_cold(void) {
    read_temperature_sensor_ExpectAndReturn(-30);
    TEST_ASSERT_EQUAL(-1, check_temperature());
}

void test_check_temperature_should_return_0_when_normal(void) {
    read_temperature_sensor_ExpectAndReturn(22);
    TEST_ASSERT_EQUAL(0, check_temperature());
}


// Testes supplémentaires : Cas limites exacts
void test_check_temperature_should_handle_exact_limits(void) {
    read_temperature_sensor_ExpectAndReturn(-40); // Limite basse
    TEST_ASSERT_EQUAL(-1, check_temperature());

    read_temperature_sensor_ExpectAndReturn(125); // Limite haute
    TEST_ASSERT_EQUAL(1, check_temperature());

    /* ++ Vous pouvez ajouter d'autres tests pour explorer les limites ++ */
}


void test_check_temperature_should_return_minus_2_when_sensor_fails(void) {
    // Simule un échec du capteur avec une température hors norme
    read_temperature_sensor_ExpectAndReturn(130); 
    TEST_ASSERT_EQUAL(-2, check_temperature()); 

    read_temperature_sensor_ExpectAndReturn(-45);
    TEST_ASSERT_EQUAL(-2, check_temperature()); 
}

