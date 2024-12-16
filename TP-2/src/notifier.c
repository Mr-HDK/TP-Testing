#include "notifier.h"
#include "utils.h"
#include <stdio.h>

void notify_threshold_exceeded(int value) {
    log_data(value);
    printf("ALERT: Value %d exceeds the threshold!\n", value);
}
