*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn



*** Test Cases ***
Test Température Critique
    [Documentation]    Vérifie que pour une température de 120°C :
    ...                - La température est invalide.
    ...                - Aucune action (chauffage ou ventilateur) n'est prise.
    ...                - Une notification est envoyée pour alerter d'une température critique.

    # Étape 1 : Fixer la température à 120°C
    ${temperature}=    Set Variable    120
    Log    Température fixée à ${temperature} °C

    # Étape 2 : Vérification de la validité de la température
    Température Doit ÊTre InValide    ${temperature}
    Log    Validation de la température terminée

    # Étape 3 : Vérifier qu'aucune action n'est déclenchée
    ${action}=    Tester Action Température    ${temperature}
    Log    Action évaluée : ${action}
    Should Be Equal    ${action}    No action
    Log    Aucune action déclenchée pour température critique

    # Étape 4 : Envoyer une notification
    Envoyer Notification Température Critique    ${temperature}
    Log    Notification envoyée pour température critique : ${temperature}°C

*** Keywords ***
Température Doit ÊTre InValide
    [Arguments]    ${temperature}
    ${result}=    Is Valid Temperature    ${temperature}
    Run Keyword If    ${result}    Fail    Température valide détectée: ${temperature}
    Log    Température invalide confirmée: ${temperature}

Tester Action Température
    [Arguments]    ${temperature}
    ${action}=    Run Keyword If    ${temperature} < 100    Get Heating Action
    ...    ELSE IF    ${temperature} > 100 and ${temperature} < 110    Get Cooling Action
    ...    ELSE    Set Variable    No action
    Log    Action déterminée pour ${temperature}°C : ${action}
    RETURN    ${action}

Envoyer Notification Température Critique
    [Arguments]    ${temperature}
    Log     Notification : Température critique détectée à ${temperature}°C

Get Heating Action
    Log    Action de chauffage déclenchée
    RETURN    Heating

Get Cooling Action
    Log    Action de refroidissement déclenchée
    RETURN    Cooling
