import random
from config import MIN_TEMP_THRESHOLD, MAX_TEMP_THRESHOLD

def read_temperature(custom_value=None):
    """
    Simule la lecture d'une température par un capteur.
    Peut retourner une valeur hors plage ou None pour simuler un capteur défectueux.
    """
    if custom_value is not None:
        return float(custom_value)
    # Simule un capteur défectueux avec une probabilité de 10%
    if random.random() < 0.1:
        return random.choice([None, random.uniform(0, MIN_TEMP_THRESHOLD - 1), random.uniform(MAX_TEMP_THRESHOLD + 1, 100)])
    return random.uniform(MIN_TEMP_THRESHOLD, MAX_TEMP_THRESHOLD)
