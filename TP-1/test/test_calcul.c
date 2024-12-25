#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));
<<<<<<< HEAD
    TEST_ASSERT_EQUAL_INT(17, addition(10, 7));
    // Complétez ici avec des cas spécifiques
    TEST_ASSERT_EQUAL_INT(16, addition(9,7));
    TEST_ASSERT_EQUAL_INT(0, addition(0,0));
    TEST_ASSERT_EQUAL_INT(-2, addition(-1,-1));
=======
    TEST_ASSERT_EQUAL_INT(17, addition(10, -7));
    // Complétez ici avec des cas spécifiques
    //TEST_ASSERT_EQUAL_INT(X, addition("""Completez ici"""));
    //TEST_ASSERT_EQUAL_INT(X, addition("""Completez ici"""));
    //TEST_ASSERT_EQUAL_INT(X, addition("""Completez ici"""));
>>>>>>> a0384ff8054af05f16353b0fcc49d473f88dec24
}

