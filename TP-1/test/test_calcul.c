#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));
    TEST_ASSERT_EQUAL_INT(3, addition(10, -7));
    // Complétez ici avec des cas spécifiques
    TEST_ASSERT_EQUAL_INT(INT_MAX, addition(INT_MIN, -1));
    TEST_ASSERT_EQUAL_INT(INT_MIN, addition(INT_MAX, 1));
    TEST_ASSERT_EQUAL_INT(-1, addition(INT_MIN, INT_MAX));
}