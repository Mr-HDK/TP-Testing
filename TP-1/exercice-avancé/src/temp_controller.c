#include "temp_controller.h"
#include "temp_sensor.h"

int check_temperature(void) {
    int temperature = read_temperature_sensor();

    if (temperature > 125 || temperature < -40) {
        return -2; // Code d'erreur pour capteur défectueux
    }
    if (temperature > 50) {
        return 1; // Trop chaud
    }
    if (temperature < 0) {
        return -1; // Trop froid
    }
    return 0; // Température normale
}
