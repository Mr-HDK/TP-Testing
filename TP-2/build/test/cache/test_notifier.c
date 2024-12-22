#include "build/test/mocks/mock_utils.h"
#include "src/notifier.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void) {}

void tearDown(void) {}





void test_notify_threshold_exceeded_triggers_alert(void) {

    int threshold_exceed_value = 120;



    log_data_CMockExpect(13, threshold_exceed_value);

    notify_threshold_exceeded(threshold_exceed_value);









}



void test_notify_threshold_exceeded_with_zero(void) {

    int zero_value = 0;





    log_data_CMockExpect(25, zero_value);





    notify_threshold_exceeded(zero_value);

}





void test_notify_threshold_exceeded_with_negative_value(void) {

    int negative_value = -50;





    log_data_CMockExpect(36, negative_value);





    notify_threshold_exceeded(negative_value);

}
