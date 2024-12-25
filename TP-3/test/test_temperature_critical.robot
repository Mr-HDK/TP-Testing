*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn

*** Test Cases ***
Gestion Température Critique Et Alerte
    [Documentation]    Test E2E pour gérer une température critique dépassant les seuils acceptables.
    
    # Étape 1 : Fixez la température à 120°C
    Log    Fixation de la température à 120°C pour le scénario critique.
    ${temperature}=    Set Variable    120
    
    # Étape 2 : Validez que la température est considérée comme invalide
    Log    Vérification que la température est invalide.
    ${result}=    Run Keyword and Return Status    Température Doit ÊTre Valide    ${temperature}
    Should Not Be True    ${result}    La température devrait être invalide.
    
    # Étape 3 : Vérifiez qu'aucune action n'est prise (chauffage ou ventilateur)
    Log    Vérification qu'aucune action n'est prise pour une température hors des seuils.
    Run Keyword If    ${temperature} < 0 or ${temperature} > 100    Tester Action Température    ${temperature}
    ...    ELSE    Log    Aucun action ne doit être prise pour une température de: ${temperature}
    
    # Étape 4 : Vérifiez qu'une notification est envoyée pour alerter
    Log    Vérification qu'une notification est envoyée pour alerter d'une température critique.
    Run Keyword If    ${temperature} < 0 or ${temperature} > 100    Tester Notification Température Hors Plage    ${temperature}
    ...    ELSE    Log    Aucune notification nécessaire pour une température de: ${temperature}°C

    # Étape 5 : Ajoutez des logs pour documenter chaque étape
    Log    Test E2E terminé avec succès.