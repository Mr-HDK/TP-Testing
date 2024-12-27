*** Settings ***
Resource    ../resources/keywords.robot
Library     BuiltIn

*** Test Cases ***
Test Notification Température Très Haute
    [Documentation]    Vérifie qu'une notification est envoyée pour une température critique (150°C).
    ${temperature}=    Set Variable    150
    ${temperature}=    Convert To Integer    ${temperature}    # Assurer que c'est un entier
    ${valid}=    Is Valid Temperature    ${temperature}
    Should Be Equal As Numbers    ${valid}    0    La température aurait dû être invalide.
    
    Tester Notification Température Hors Plage    ${temperature}
    Log    Notification envoyée pour température critique: ${temperature}°C

Test Notification Température Très Basse
    [Documentation]    Vérifie qu'une notification est envoyée pour une température critique basse (-50°C).
    ${temperature}=    Set Variable    -50
    ${temperature}=    Convert To Integer    ${temperature}    # Assurer que c'est un entier
    ${valid}=    Is Valid Temperature    ${temperature}
    Should Be Equal As Numbers    ${valid}    0    La température aurait dû être invalide.
    
    Tester Notification Température Hors Plage    ${temperature}
    Log    Notification envoyée pour température critique: ${temperature}°C

Test Aucune Notification Température Normale
    [Documentation]    Vérifie qu'aucune notification n'est envoyée pour une température normale (30°C).
    ${temperature}=    Set Variable    30
    ${temperature}=    Convert To Integer    ${temperature}    # Assurer que c'est un entier
    ${valid}=    Is Valid Temperature    ${temperature}
    Should Be Equal As Numbers    ${valid}    1    La température devrait être valide.

    Run Keyword If    ${temperature} < 0 or ${temperature} > 100    Tester Notification Température Hors Plage    ${temperature}
    Run Keyword If    ${temperature} >= 0 and ${temperature} <= 100    Log    Aucune notification nécessaire pour ${temperature}°C