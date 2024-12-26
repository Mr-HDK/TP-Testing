#include "temp_controller.h"
#include "temp_sensor.h"

int check_temperature(void) {
    int temperature = read_temperature_sensor();

     // Vérifier les cas où la température dépasse les limites hardware
    if (temperature > 125 || temperature < -40) {
        return -2; // Échec du capteur (valeurs hors normes)
    }

    // Vérifier les températures normales
    if (temperature > 30) {
        return 1; // Trop chaud
    } else if (temperature < 15) {
        return -1; // Trop froid
    } else {
        return 0; // Température normale
    }
}
