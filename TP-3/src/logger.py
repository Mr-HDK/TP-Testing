import logging

logging.basicConfig(filename='temperature_log.txt', level=logging.INFO)

def log_temperature(temperature, action):
    """
    Enregistre les températures et actions dans un fichier log.
    """
    logging.info(f"Température: {temperature}°C | Action: {action}")
