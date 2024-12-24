*** Settings ***
Resource    ../resources/keywords.robot
Library     BuiltIn

*** Test Cases ***
Test Action Chauffage à Température Très Basse
    [Documentation]    Vérifie que le chauffage s'active pour une température très basse (-5°C).
    ${temperature}=    Set Variable    -5
    Log    Température utilisée: ${temperature}

    ${action}=    Tester Action Température    ${temperature}
    Should Be Equal    ${action}    Heater activated
    Log    Action prise: ${action}

Test Action Température Optimale
    [Documentation]    Vérifie qu'aucune action n'est prise pour une température optimale (22°C).
    ${temperature}=    Set Variable    22
    Log    Température utilisée: ${temperature}

    ${action}=    Tester Action Température    ${temperature}
    Should Be Equal    ${action}    Temperature is in optimal range
    Log    Action prise: ${action}

Test Action Ventilateur à Température Élevée
    [Documentation]    Vérifie que le ventilateur s'active pour une température élevée (80°C).
    ${temperature}=    Set Variable    80
    Log    Température utilisée: ${temperature}

    ${action}=    Tester Action Température    ${temperature}
    Should Be Equal    ${action}    Fan activated
    Log    Action prise: ${action}