#include "src/calcul.h"
#include "/home/rawaa/.rbenv/versions/2.7.8/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void test_addition(void) {

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((addition(2, 3))), (

   ((void *)0)

   ), (UNITY_UINT)(5), UNITY_DISPLAY_STYLE_INT);

<<<<<<< HEAD
    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((addition(10, -7))), (
=======
    UnityAssertEqualNumber((UNITY_INT)((17)), (UNITY_INT)((addition(10, 7))), (
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

   ((void *)0)

   ), (UNITY_UINT)(6), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((addition(0, 0))), (

   ((void *)0)

   ), (UNITY_UINT)(8), UNITY_DISPLAY_STYLE_INT);

<<<<<<< HEAD
    UnityAssertEqualNumber((UNITY_INT)((

   (-0x7fffffff - 1)

   )), (UNITY_INT)((addition(0x7fffffff

   , 1))), (
=======
    UnityAssertEqualNumber((UNITY_INT)((100000)), (UNITY_INT)((addition(99999, 1))), (
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

   ((void *)0)

   ), (UNITY_UINT)(9), UNITY_DISPLAY_STYLE_INT);

<<<<<<< HEAD
    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((addition(0x7fffffff

   , 

   (-0x7fffffff - 1)

   ))), (
=======
    UnityAssertEqualNumber((UNITY_INT)((-5)), (UNITY_INT)((addition(-2, -3))), (
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e

   ((void *)0)

   ), (UNITY_UINT)(10), UNITY_DISPLAY_STYLE_INT);

<<<<<<< HEAD
    UnityAssertEqualNumber((UNITY_INT)((0x7fffffff

   )), (UNITY_INT)((addition(

   (-0x7fffffff - 1)

   , -1))), (

   ((void *)0)

   ), (UNITY_UINT)(11), UNITY_DISPLAY_STYLE_INT);

}
=======








    }
>>>>>>> d7a8a5521c3e7027c0be68dd87145f68b18e7b8e
