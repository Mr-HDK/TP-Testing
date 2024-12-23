#include "build/test/mocks/mock_utils.h"
#include "src/notifier.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void) {}

void tearDown(void) {}



void test_notify_threshold_exceeded_triggers_alert(void) {

    int threshold_exceed_value = 120;



    log_data_CMockExpect(12, threshold_exceed_value);

    notify_threshold_exceeded(threshold_exceed_value);





}
