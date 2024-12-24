import random
import csv

def read_temperature(custom_value=None):
    """
    Simule la lecture d'une température par un capteur.
    Si une valeur personnalisée est fournie, elle est utilisée.
    Sinon, retourne une température aléatoire dans la plage [0, 100]°C,
    ou simule un capteur défectueux avec une probabilité.
    """
    # Si une valeur personnalisée est fournie, l'utiliser directement
    if custom_value is not None:
        temperature = float(custom_value)
        log_to_csv(temperature, "Valid")
        return temperature

    # Simuler un défaut du capteur avec une probabilité de 10%
    if random.random() < 0.1:
        log_to_csv(None, "Sensor Error")
        return None  # Simuler un échec du capteur en retournant None

    # Simuler une température hors plage avec une probabilité de 10%
    if random.random() < 0.1:
        log_to_csv(-100, "Out of Range")
        return -100  # Température hors plage pour simuler une erreur

    # Retourner une température valide entre 0 et 100°C
    temperature = random.uniform(0, 100)
    log_to_csv(temperature, "Valid")
    return temperature

def log_to_csv(temperature, status):
    """
    Enregistre la température et son statut dans un fichier CSV.
    """
    with open('sensor_test_results.csv', 'a', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([temperature, status])
