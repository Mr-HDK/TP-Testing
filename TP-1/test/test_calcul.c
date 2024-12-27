#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));
    TEST_ASSERT_EQUAL_INT(3, addition(10, -7));
    TEST_ASSERT_EQUAL_INT(2, addition(1, 1));  
    TEST_ASSERT_EQUAL_INT(0, addition(1, -1));
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));  
    TEST_ASSERT_EQUAL_INT(-2, addition(-1, -1)); 
    TEST_ASSERT_EQUAL_INT(10, addition(7, 3));     
}