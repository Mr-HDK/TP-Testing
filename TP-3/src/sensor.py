import random

def read_temperature(custom_value=None):
    """
    Simule la lecture d'une température par un capteur.
    Si une valeur personnalisée est fournie, elle est utilisée.
    Sinon, retourne une température aléatoire dans la plage [0, 100]°C.
    """
    if custom_value is not None:
        return float(custom_value)
    return random.uniform(0, 100)  # Plage corrigée pour être dans l'intervalle valide