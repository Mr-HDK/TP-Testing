#include "src/calcul.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void test_addition(void) {

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((addition(2, 3))), (

   ((void *)0)

   ), (UNITY_UINT)(5), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((17)), (UNITY_INT)((addition(10, 7))), (

   ((void *)0)

   ), (UNITY_UINT)(6), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((UNITY_INT)((16)), (UNITY_INT)((addition(9,7))), (

   ((void *)0)

   ), (UNITY_UINT)(8), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((addition(0,0))), (

   ((void *)0)

   ), (UNITY_UINT)(9), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-2)), (UNITY_INT)((addition(-1,-1))), (

   ((void *)0)

   ), (UNITY_UINT)(10), UNITY_DISPLAY_STYLE_INT);

}
