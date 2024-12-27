from config import MIN_TEMP_THRESHOLD, MAX_TEMP_THRESHOLD

def is_valid_temperature(temperature):
    """
    Vérifie si la température est dans la plage valide en utilisant les seuils configurés.
    """
    try:
        # Assurez-vous que la température est un nombre valide
        temperature = float(temperature)
    except (ValueError, TypeError):
        return False  # Entrée invalide
    
    # Vérifie si la température est en dehors des seuils
    if temperature < MIN_TEMP_THRESHOLD or temperature > MAX_TEMP_THRESHOLD:
        return False  # Température hors des limites
    return True  # Température valide