#include "src/utils.h"
#include "src/notifier.h"
#include "C:/Users/HP/TP-Testing/TP-2/vendor/ceedling/vendor/unity/src/unity.h"






void setUp(void) {}

void tearDown(void) {}



void test_notify_threshold_exceeded_triggers_alert(void) {

    int threshold_exceed_value = 120;





    char output_buffer[256];

    setbuf(

          (&_iob[1])

                , output_buffer);





    notify_threshold_exceeded(threshold_exceed_value);







    do {if ((strstr(output_buffer, "ALERT: Value 120 exceeds the threshold!") != 

   ((void *)0)

   )) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(23)));}} while(0);

}



void test_notify_threshold_not_exceeded_does_not_trigger_alert(void) {

    int threshold_non_exceed_value = 80;





    char output_buffer[256];

    setbuf(

          (&_iob[1])

                , output_buffer);





    notify_threshold_exceeded(threshold_non_exceed_value);





    UnityAssertEqualString((const char*)(("")), (const char*)((output_buffer)), (

   ((void *)0)

   ), (UNITY_UINT)(37));

}
