*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn

*** Test Cases ***
Gestion Température Critique Et Alerte
    [Documentation]    Gestion d'une température critique dépassant les seuils acceptables.

    # Étape 1
    ${temperature}=    Set Variable    120
    
    # Étape 2
    ${is_valid}=    Run Keyword and Return Status    Température Doit ÊTre Valide    ${temperature}
    Should Not Be True    ${is_valid}    La température devrait être invalide.
    
    # Étape 3
    Run Keyword If    ${temperature} < 0 or ${temperature} > 100    Tester Action Température    ${temperature}
    ...    ELSE    Log    Aucun action ne doit être prise.
    
    # Étape 4
    Run Keyword If    ${temperature} < 0 or ${temperature} > 100    Tester Notification Température Hors Plage    ${temperature}
    ...    ELSE    Log    Aucune notification nécessaire.
    
    # Étape 5
    Log    Test E2E terminé avec succès.