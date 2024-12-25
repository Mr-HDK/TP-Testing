*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn

*** Variables ***
${CRITICAL_TEMPERATURE}    120  # Température critique au-delà des seuils acceptables
${EXPECTED_NOTIFICATION}   Température critique détectée : ${CRITICAL_TEMPERATURE}°C

*** Test Cases ***
Gestion d'une Température Critique et Notification
    [Documentation]    Ce test vérifie qu'aucune action n'est prise pour une température critique
    ...               et qu'une notification est envoyée correctement.

    # Étape 1 : Fixer la température à une valeur critique (120°C)
    Log    Étape 1 : Fixation de la température critique à ${CRITICAL_TEMPERATURE}°C
    Set Temperature    ${CRITICAL_TEMPERATURE}

    # Étape 2 : Valider que la température est considérée comme invalide
    Log    Étape 2 : Vérification si la température est invalide
    ${is_valid}    Is Temperature Valid    ${CRITICAL_TEMPERATURE}
    Should Be False    ${is_valid}    La température critique doit être invalide

    # Étape 3 : Vérifier qu'aucune action (chauffage ou ventilateur) n'est prise
    Log    Étape 3 : Vérification qu'aucune action n'est prise pour une température hors seuil
    ${heating_status}    Get Heating Status
    ${fan_status}        Get Fan Status
    Should Be False    ${heating_status}    Le chauffage ne doit pas être activé pour une température critique
    Should Be False    ${fan_status}        Le ventilateur ne doit pas être activé pour une température critique

    # Étape 4 : Vérifier qu'une notification est envoyée
    Log    Étape 4 : Vérification de l'envoi d'une notification pour température critique
    ${notification}    Get Last Notification
    Should Be Equal    ${notification}    ${EXPECTED_NOTIFICATION}    La notification doit indiquer une température critique

    # Étape 5 : Ajout des logs pour documenter chaque étape
    Log    Étape 5 : Toutes les vérifications ont été effectuées avec succès

*** Keywords ***
Set Temperature
    [Arguments]    ${temperature}
    Log    Réglage de la température à ${temperature}°C
    # Simule le réglage de la température dans le système
    Set Temperature Keyword    ${temperature}

Is Temperature Valid
    [Arguments]    ${temperature}
    Log    Validation de la température : ${temperature}°C
    # Retourne True si la température est dans les seuils acceptables, sinon False
    ${is_valid}    Evaluate    ${temperature} >= 0 and ${temperature} <= 100
    Return    ${is_valid}

Get Heating Status
    Log    Récupération de l'état du chauffage
    # Simule la récupération de l'état du chauffage (activé/désactivé)
    ${status}    Get Heating Status Keyword
    Return    ${status}

Get Fan Status
    Log    Récupération de l'état du ventilateur
    # Simule la récupération de l'état du ventilateur (activé/désactivé)
    ${status}    Get Fan Status Keyword
    Return    ${status}

Get Last Notification
    Log    Récupération de la dernière notification envoyée
    # Simule la récupération du dernier message de notification
    ${notification}    Get Last Notification Keyword
    Return    ${notification}
