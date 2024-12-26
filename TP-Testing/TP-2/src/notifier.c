#include "notifier.h"


void notify_threshold_exceeded(int value) {
    printf("ALERT: Value %d exceeds the threshold!\n", value);
}
