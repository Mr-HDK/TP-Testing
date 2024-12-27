import random
def read_temperature(custom_value=None):
    """
    Simule la lecture d'une température par un capteur.
    Retourne None pour simuler un capteur défectueux.
    """
    if custom_value is not None:
        return float(custom_value)
    if random.random() < 0.1:  # 10% de chances de défaillance
        return None
    return random.uniform(0, 100)

def validate_temperature(temperature):
    """
    Vérifie si une température est valide.
    - Doit être différente de None.
    - Doit être dans la plage -40°C à 120°C.
    """
    if temperature is None:
        return False
    return -10 <= temperature <= 100
