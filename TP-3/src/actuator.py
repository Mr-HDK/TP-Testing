def control_temperature(temperature):
    """
    Simule l'activation d'un chauffage ou d'un ventilateur en fonction de la température.
    Si la température est trop basse, active le chauffage.
    Si elle est trop haute, active le ventilateur.
    """
    if temperature < 18:
        return "Heater activated"
    elif temperature > 28:
        return "Fan activated"
    else:
        return "Temperature is in optimal range"
