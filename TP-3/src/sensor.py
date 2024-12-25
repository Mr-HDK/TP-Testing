import random

def read_temperature(custom_value=None):
    """
    Simule la lecture d'une température par un capteur.
    Si une valeur personnalisée est fournie, elle est utilisée.
    Sinon, retourne une température aléatoire dans la plage [0, 150]°C.
    """
    if custom_value is not None:
        return float(custom_value)
    return random.uniform(0, 150)  # Dépasse la plage valide [0, 100]°C 
                                   # à vous de la changer.
    

def temperature_is_valid(temperature):
    """
    Vérifie si la température est valide.
    Cette fonction s'assure que la température est dans la plage de 0 à 100 °C.
    """
    if temperature < 0 or temperature > 100:
        raise ValueError(f"Température invalide: {temperature}. La température doit être entre 0 et 100 °C.")
    return True

def test_temperature_action(temperature):
    """
    Simule l'activation d'un chauffage ou d'un ventilateur en fonction de la température.
    Retourne "Heater activated" si la température est inférieure à 15°C,
    "Fan activated" si elle est supérieure à 30°C, sinon "No action".
    """
    if temperature < 15:
        return "Heater activated"
    elif temperature > 30:
        return "Fan activated"
    return "No action"

def notify_temperature_out_of_range(temperature):
    """
    Envoie une notification si la température est en dehors de la plage valide (en dehors de 0 à 100 °C).
    """
    if temperature < 0 or temperature > 100:
        print(f"Température hors plage: {temperature}")
