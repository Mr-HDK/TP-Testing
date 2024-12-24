from config import MIN_TEMP_THRESHOLD, MAX_TEMP_THRESHOLD

def is_valid_temperature(temperature):
    """
    Vérifie si la température est dans la plage valide en utilisant les seuils configurés.
    """
    return MIN_TEMP_THRESHOLD <= temperature <= MAX_TEMP_THRESHOLD

def SendAlert(message):
    """
    Envoie une alerte (par exemple, par email, SMS, ou log) pour la température critique.
    Retourne True si l'alerte a été envoyée avec succès, sinon False.
    """
    # Exemple de logique pour envoyer une alerte, ici juste un log pour démonstration
    print(f"Alerte envoyée: {message}")
    return True  # Retourne True si l'alerte est envoyée avec succès

def CheckSystemActions():
    """
    Vérifie les actions du système (chauffage, ventilateur) pour s'assurer qu'aucune action n'est prise.
    Retourne True si une action est prise, sinon False.
    """
    # Logique pour vérifier les actions système, par exemple vérifier si le chauffage ou le ventilateur est activé
    heating_on = False  # Exemple: Remplacez par la logique réelle pour vérifier si le chauffage est activé
    fan_on = False  # Exemple: Remplacez par la logique réelle pour vérifier si le ventilateur est activé
    
    if heating_on or fan_on:
        return True
    return False
