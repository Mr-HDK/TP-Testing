#include "unity.h"
#include "notifier.h"
#include "mock_utils.h" // Mocked logging function


void setUp(void) {}
void tearDown(void) {}


void test_notify_threshold_exceeded_triggers_alert(void) {
    int threshold_exceed_value = 120;

    log_data_Expect(threshold_exceed_value); // Expectation for logging
    notify_threshold_exceeded(threshold_exceed_value);

    // Additional verification can include mocking `printf` output.
    

}
//mocked log_data function with 0 
void test_notify_threshold_exceeded_with_zero(void) {
    int zero_value = 0;


    log_data_Expect(zero_value);

    
    notify_threshold_exceeded(zero_value);
}

//mocked log_data function with negative value
void test_notify_threshold_exceeded_with_negative_value(void) {
    int negative_value = -50;


    log_data_Expect(negative_value);


    notify_threshold_exceeded(negative_value);
}




