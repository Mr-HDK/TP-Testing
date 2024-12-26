#include "unity.h"
#include "calcul.h"

void test_addition(void) {
    TEST_ASSERT_EQUAL_INT(5, addition(2, 3));    
    TEST_ASSERT_EQUAL_INT(3, addition(10, -7));  
    TEST_ASSERT_EQUAL_INT(0, addition(0, 0));    
    TEST_ASSERT_EQUAL_INT(-5, addition(-2, -3)); 
    TEST_ASSERT_EQUAL_INT(100, addition(50, 50)); 
    TEST_ASSERT_EQUAL_INT(-1, addition(2, -3));  
    TEST_ASSERT_EQUAL_INT(1, addition(-4, 5));   
    TEST_ASSERT_EQUAL_INT(2000000, addition(1000000, 1000000));  
    TEST_ASSERT_EQUAL_INT(-2000000, addition(-1000000, -1000000)); 
    TEST_ASSERT_EQUAL_INT(2147483647, addition(2147483646, 1));  
    TEST_ASSERT_EQUAL_INT(-2147483648, addition(-2147483647, -1));
    TEST_ASSERT_EQUAL_INT(4294967295, addition(2147483647, -(-2147483648)));
<<<<<<< HEAD

=======
>>>>>>> bab76acbc9095acd3e3c668928841054c901f11b
   
}

