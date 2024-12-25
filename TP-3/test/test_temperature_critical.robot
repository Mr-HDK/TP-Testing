*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn



*** Test Cases ***
Test Température Critique Hors Seuil
    [Documentation]    Vérifie que pour une température de 120°C :
    ...                - La température est hors des seuils définis.
    ...                - Aucune action (chauffage ou ventilateur) n'est prise.
    ...                - Une notification est envoyée pour alerter de la température critique.
    
    # 1. Fixer la température à 120°C (hors des seuils définis).
    ${temperature}=    Set Variable    120
    Log    Température fixée à : ${temperature}°C
    
    # 2. Valider que la température est considérée comme invalide (hors des seuils).
    Tester Notification Température Hors Plage    ${temperature}
    Log    Température validée comme hors seuil.
    
    # 3. Vérifier qu'aucune action n'est prise (ni chauffage, ni ventilateur).
    ${action}=    process_temperature    ${temperature}
    Should Be Equal    ${action}    No action
    Log    Aucune action prise pour une température hors seuil.
    
    # 4. Vérifier qu'une notification est envoyée pour alerter d'une température critique.
    Run Keyword If    ${temperature} < 0 or ${temperature} > 100  Tester Notification Température Hors Plage    ${temperature}
    ...    ELSE    Log    Pas de notification nécessaire pour ${temperature}°C

