#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));
    TEST_ASSERT_EQUAL_INT(17, addition(10, 7));
 // Edge cases
    //TEST_ASSERT_EQUAL_INT(0, addition(0, 0));          // Adding two zeros
    //TEST_ASSERT_EQUAL_INT(100000, addition(99999, 1)); // Adding large numbers
    //TEST_ASSERT_EQUAL_INT(-5, addition(-2, -3));       // Adding two negatives

    //Overflow cases (if addition handles them)
    //TEST_ASSERT_EQUAL_INT(INT_MAX, addition(INT_MAX, 0)); // Adding zero to INT_MAX
    //TEST_ASSERT_EQUAL_INT(INT_MIN, addition(INT_MIN, 0)); // Adding zero to INT_MIN
    }