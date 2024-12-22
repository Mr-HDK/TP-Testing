import random

def read_temperature():
    """
    Simule la lecture d'une température par un capteur.
    Retourne une température aléatoire dans la plage [0, 150]°C.
    """
    return random.uniform(0, 150)
