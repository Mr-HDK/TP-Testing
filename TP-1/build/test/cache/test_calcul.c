#include "src/calcul.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void test_addition(void) {

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((addition(2, 3))), (

   ((void *)0)

   ), (UNITY_UINT)(5), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((addition(10, -7))), (

   ((void *)0)

   ), (UNITY_UINT)(6), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((addition(0, 0))), (

   ((void *)0)

   ), (UNITY_UINT)(7), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-5)), (UNITY_INT)((addition(-2, -3))), (

   ((void *)0)

   ), (UNITY_UINT)(8), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((100)), (UNITY_INT)((addition(50, 50))), (

   ((void *)0)

   ), (UNITY_UINT)(9), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((addition(2, -3))), (

   ((void *)0)

   ), (UNITY_UINT)(10), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((addition(-4, 5))), (

   ((void *)0)

   ), (UNITY_UINT)(11), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2000000)), (UNITY_INT)((addition(1000000, 1000000))), (

   ((void *)0)

   ), (UNITY_UINT)(12), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-2000000)), (UNITY_INT)((addition(-1000000, -1000000))), (

   ((void *)0)

   ), (UNITY_UINT)(13), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2147483647)), (UNITY_INT)((addition(2147483646, 1))), (

   ((void *)0)

   ), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-2147483648)), (UNITY_INT)((addition(-2147483647, -1))), (

   ((void *)0)

   ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4294967295)), (UNITY_INT)((addition(2147483647, -(-2147483648)))), (

   ((void *)0)

   ), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT);





}
