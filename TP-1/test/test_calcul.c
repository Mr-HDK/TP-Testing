#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));
    TEST_ASSERT_EQUAL_INT(3, addition(10, -7));
<<<<<<< HEAD
    // Complétez ici avec des cas spécifiques
    TEST_ASSERT_EQUAL_INT(-6, addition(-3, -3));
    TEST_ASSERT_EQUAL_INT(-7, addition(0, -7));
    TEST_ASSERT_EQUAL_INT(-3, addition(-5, 2));
    TEST_ASSERT_EQUAL_INT(2, addition(0, 2));
    TEST_ASSERT_EQUAL_INT(0, addition(0, 0));

=======
    //Complétez ici avec des cas spécifiques
    TEST_ASSERT_EQUAL_INT(8, addition(4, 4));
    TEST_ASSERT_EQUAL_INT(11, addition(-9, 20));
    TEST_ASSERT_EQUAL_INT(0, addition(0, 0));
    TEST_ASSERT_EQUAL_INT(-6, addition(-3, -3));
>>>>>>> 634ecb1e99d0c160230b7d33338256a701f92050
}

