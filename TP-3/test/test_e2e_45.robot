*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn

*** Test Cases ***
Test Spécifique Température 45°C
    [Documentation]    Vérifie que pour une température de 45°C :
    ...                - La température est dans les seuils.
    ...                - L'action attendue est "ventilateur activé".
    ...                - Aucun message de notification n'est envoyé.

    ${temperature}=    Set Variable    45
    Température Doit ÊTre Valide    ${temperature}

    ${action}=    Tester Action Température    ${temperature}
    Should Be Equal    ${action}    Fan activated

    Run Keyword If    ${temperature} < 0 or ${temperature} > 100    Tester Notification Température Hors Plage    ${temperature}
    ...    ELSE    Log    Pas de notification nécessaire pour ${temperature}°C