from utils import is_valid_temperature
from notifier import send_notification
from actuator import control_temperature
from config import MIN_TEMP_THRESHOLD, MAX_TEMP_THRESHOLD

def process_temperature(temperature):
    """
    Processus de gestion de la température lue.
    Si la température est dans la plage valide, renvoie la température traitée.
    Si elle est hors de la plage, envoie une alerte.
    Après traitement, active l'actuateur pour ajuster la température.
    """
    if MIN_TEMP_THRESHOLD <= temperature <= MAX_TEMP_THRESHOLD:
        # Traitement de la température si elle est dans la plage valide
        result = control_temperature(temperature)
        return round(temperature, 1), result
    else:
        send_notification(f"Alerte : Température hors plage ({temperature}°C)")
        return round(temperature, 1), "No action"
