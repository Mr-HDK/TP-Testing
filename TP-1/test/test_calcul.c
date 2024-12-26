#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));
<<<<<<< HEAD
    TEST_ASSERT_EQUAL_INT(3, addition(10, -7));
    // Complétez ici avec des cas spécifiques
    TEST_ASSERT_EQUAL_INT(0, addition(0, 0));
    TEST_ASSERT_EQUAL_INT(INT_MIN, addition(INT_MAX, 1));
    TEST_ASSERT_EQUAL_INT(-1, addition(INT_MAX, INT_MIN));
    TEST_ASSERT_EQUAL_INT(INT_MAX, addition(INT_MIN, -1));
}
=======
    TEST_ASSERT_EQUAL_INT(17, addition(10, 7));
     // Edge cases
    TEST_ASSERT_EQUAL_INT(0, addition(0, 0));          // Adding two zeros
    TEST_ASSERT_EQUAL_INT(100000, addition(99999, 1)); // Adding large numbers
    TEST_ASSERT_EQUAL_INT(-5, addition(-2, -3));       // Adding two negatives

   // Overflow cases (if addition handles them)
    //TEST_ASSERT_EQUAL_INT(INT_MAX, addition(INT_MAX, 0)); // Adding zero to INT_MAX
    //TEST_ASSERT_EQUAL_INT(INT_MIN, addition(INT_MIN, 0)); // Adding zero to INT_MIN
    }


>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e
