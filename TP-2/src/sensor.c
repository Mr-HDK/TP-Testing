#include "sensor.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


int read_sensor(void) {
    return rand() % 150;  // Simule une lecture aléatoire (plage élargie pour tests) avec possibilité d'érreurs.
}

bool is_valid_value(int value) {
    return value >= 0 && value <= 100;
}
