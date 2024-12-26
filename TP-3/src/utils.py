from config import MIN_TEMP_THRESHOLD, MAX_TEMP_THRESHOLD

def is_valid_temperature(temperature):
    """
    Vérifie si la température est dans la plage valide en utilisant les seuils configurés.
    """
    try:
        temperature = int(temperature)  # Ensure temperature is an integer
    except ValueError:
        return False  # Invalid input

    return MIN_TEMP_THRESHOLD <= temperature <= MAX_TEMP_THRESHOLD