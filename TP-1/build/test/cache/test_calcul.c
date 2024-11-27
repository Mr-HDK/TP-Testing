#include "src/calcul.h"




void test_addition(void) {

    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));

    TEST_ASSERT_EQUAL_INT(17, addition(10, -7));



    TEST_ASSERT_EQUAL_INT(-2, addition(-5,3));

    TEST_ASSERT_EQUAL_INT(100, addition(57,43));

    TEST_ASSERT_EQUAL_INT(14, addition(8,9));

}
