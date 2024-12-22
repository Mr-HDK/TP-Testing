#include "unity.h"
#include "sensor.h"

void setUp(void) {} // good practice
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

