#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));
    TEST_ASSERT_EQUAL_INT(17, addition(10, -7));
<<<<<<< HEAD
=======
    TEST_ASSERT_EQUAL_INT(11, addition(-4, -7));
    TEST_ASSERT_EQUAL_INT(17, addition(-10, -7));
>>>>>>> 71c171c2c7d777269ac98284c8b1ebe4a31df300
    // Complétez ici avec des cas spécifiques
    //TEST_ASSERT_EQUAL_INT(X, addition("""Completez ici"""));
    //TEST_ASSERT_EQUAL_INT(X, addition("""Completez ici"""));
    //TEST_ASSERT_EQUAL_INT(X, addition("""Completez ici"""));
}

