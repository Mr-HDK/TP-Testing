#include "temp_controller.h"
#include "temp_sensor.h"

int check_temperature(void) {
    int temp = read_temperature_sensor();

    // Vérification des limites matérielles
    if (temp > 125 || temp < -40) {
        return -2; // Erreur capteur
    }

    // Vérification des plages normales
    if (temp > 80) {
        return 1; // Trop chaud
    } else if (temp < 0) {
        return -1; // Trop froid
    } else {
        return 0; // Normal
    }
}
