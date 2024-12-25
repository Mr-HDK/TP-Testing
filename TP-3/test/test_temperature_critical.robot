*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn

# SCÉNARIO : Gestion d'une température critique et d'une alerte
# 
# Objectif : Implémentez un test E2E pour gérer un scénario où la température dépasse 
# les seuils acceptables et où une notification doit être envoyée.
#
# Instructions :
# 1. Fixez la température à 120°C (hors des seuils définis par `utils.py`).
# 2. Validez que la température est considérée comme invalide.
# 3. Vérifiez qu'aucune action (chauffage ou ventilateur) n'est prise, car la température est hors seuil.
# 4. Vérifiez qu'une notification est envoyée pour alerter d'une température critique.
# 5. Ajoutez des logs pour documenter chaque étape du test.
#
# Critères de validation :
# - Le test doit échouer si une action est prise pour une température hors seuil.
# - Une notification doit être loggée avec un message indiquant que la température est critique.
# - Chaque étape doit être documentée par un log clair.
