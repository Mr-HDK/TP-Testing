#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));
    TEST_ASSERT_EQUAL_INT(17, addition(10, 7));
    // Complétez ici avec des cas spécifiques
    TEST_ASSERT_EQUAL_INT(-2, addition(-10, 8));
    TEST_ASSERT_EQUAL_INT(15, addition(10, 5));
    TEST_ASSERT_EQUAL_INT(24, addition(12, 12	));
    //TEST_ASSERT_EQUAL_INT(X, addition("""Completez ici"""));
    //TEST_ASSERT_EQUAL_INT(X, addition("""Completez ici"""));
}

