#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));
    TEST_ASSERT_EQUAL_INT(17, addition(10,-7));
    // Complétez ici avec des cas spécifiques
    TEST_ASSERT_EQUAL_INT(0, addition(0, 0));
    TEST_ASSERT_EQUAL_INT(-5, addition(-2, -3));
    TEST_ASSERT_EQUAL_INT(3, addition(6, -3));
}
