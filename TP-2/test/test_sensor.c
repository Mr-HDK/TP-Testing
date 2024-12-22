#include "unity.h"
#include "sensor.h"
#include <stdlib.h>

void setUp(void) {      // good practice 
    srand(42);          // Fixed seed for reproducibility
} 
void tearDown(void) {} // good practice


void test_read_sensor_returns_within_expected_range(void) {
    for (int i = 0; i < 100; i++) { // Run multiple iterations for randomness.
        int value = read_sensor();
        TEST_ASSERT(value >= 0 && value < 150);
    }
}

void test_is_valid_value_identifies_correct_boundaries(void) {
    TEST_ASSERT_TRUE(is_valid_value(50));   // Valid middle value
    TEST_ASSERT_TRUE(is_valid_value(0));    // Lower boundary
    TEST_ASSERT_TRUE(is_valid_value(100));  // Upper boundary
    TEST_ASSERT_FALSE(is_valid_value(-1));  // Below lower boundary
    TEST_ASSERT_FALSE(is_valid_value(101)); // Above upper boundary
}

void test_read_sensor_handles_sensor_error(void) {
    int value = read_sensor();
    // Si une erreur se produit, la valeur retournée doit être -1
    if (value == -1) {
        TEST_FAIL_MESSAGE("Sensor error occurred: value is -1");
    } else {
        TEST_ASSERT(value >= 0 && value < 150);  // Si pas d'erreur, vérifier la plage de valeurs
    }
}