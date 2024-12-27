import logging

# Configuration pour les logs
logging.basicConfig(
    filename='temperature_log.txt', 
    level=logging.INFO, 
    format='%(asctime)s - %(levelname)s - %(message)s'
)

def log_temperature(temperature, action):
    """
    Enregistre les températures et actions dans un fichier log.
    """
    logging.info(f"Température: {temperature}°C | Action: {action}")

def log_error(message):
    """
    Enregistre un message d'erreur dans le fichier log.
    """
    logging.error(f"Erreur: {message}")
