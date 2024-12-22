*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn

*** Variables ***
${TEMP_INVALID_LOW}    -100
${TEMP_INVALID_HIGH}   200
${NO_ACTION}           No action

*** Test Cases ***
Gestion Des Capteurs Défectueux
    [Documentation]    Teste le comportement du système avec des capteurs défectueux.
    
    # Étape 1 : Simuler une température hors plage basse
    Log    Vérification pour une température hors plage basse.
    ${temperature}=    Set Variable    ${TEMP_INVALID_LOW}
    ${is_valid}=       Run Keyword And Return Status    Température Doit ÊTre Valide    ${temperature}
    Should Be Equal    ${is_valid}    ${False}    La température basse ${temperature}°C a été incorrectement validée comme valide.
    Log    Validation réussie : la température basse ${temperature}°C est bien non valide.
    
    # Étape 2 : Simuler une température hors plage haute
    Log    Vérification pour une température hors plage haute.
    ${temperature}=    Set Variable    ${TEMP_INVALID_HIGH}
    ${is_valid}=       Run Keyword And Return Status    Température Doit ÊTre Valide    ${temperature}
    Should Be Equal    ${is_valid}    ${False}    La température haute ${temperature}°C a été incorrectement validée comme valide.
    Log    Validation réussie : la température haute ${temperature}°C est bien non valide.
    
    # Étape 3 : Vérifier le comportement avec une valeur None
    Log    Vérification pour une valeur None (capteur défectueux).
    ${temperature}=    Set Variable    ${None}
    ${is_valid}=       Run Keyword And Return Status    Température Doit ÊTre Valide    ${temperature}
    Should Be Equal    ${is_valid}    ${False}    La température None a été incorrectement validée comme valide.
    Log    Validation réussie : la température None est bien non valide.
