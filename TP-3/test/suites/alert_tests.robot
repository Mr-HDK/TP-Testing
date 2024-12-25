*** Settings ***
Resource    ../resources/keywords.robot
Library     BuiltIn

*** Test Cases ***
Test Notification Température Très Haute
    [Documentation]    Vérifie qu'une notification est envoyée pour une température critique (150°C).
    ${temperature}=    Set Variable    150
    ${valid}=    Is Valid Temperature    ${temperature}
    Should Be False    ${valid}    La température aurait dû être invalide.

    Tester Notification Température Hors Plage    ${temperature}
    Log    Notification envoyée pour température critique: ${temperature}°C

Test Notification Température Très Basse
    [Documentation]    Vérifie qu'une notification est envoyée pour une température critique basse (-50°C).
    ${temperature}=    Set Variable    -50
    ${valid}=    Is Valid Temperature    ${temperature}
    Should Be False    ${valid}    La température aurait dû être invalide.

    Tester Notification Température Hors Plage    ${temperature}
    Log    Notification envoyée pour température critique: ${temperature}°C

Test Aucune Notification Température Normale
    [Documentation]    Vérifie qu'aucune notification n'est envoyée pour une température normale (30°C).
    ${temperature}=    Set Variable    30
    ${valid}=    Is Valid Temperature    ${temperature}
    Should Be True    ${valid}    La température devrait être valide.

    Run Keyword If    ${temperature} < 0 or ${temperature} > 100    Tester Notification Température Hors Plage    ${temperature}
    ELSE    Log    Aucune notification nécessaire pour ${temperature}°C
