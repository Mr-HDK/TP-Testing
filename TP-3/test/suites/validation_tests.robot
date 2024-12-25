*** Settings ***
Resource    ../resources/keywords.robot
Library     BuiltIn

*** Test Cases ***

Test Validation Température Basse Limite
    [Documentation]    Vérifie que la température minimale limite (0°C) est valide.
    ${temperature}=    Set Variable    0
    ${temperature}=    Convert To Number    ${temperature}  # Assurez-vous que c'est un nombre
    Température Doit ÊTre Valide    ${temperature}
    Log    Température validée avec succès: ${temperature}

Test Validation Température Haute Limite
    [Documentation]    Vérifie que la température maximale limite (100°C) est valide.
    ${temperature}=    Set Variable    100
    ${temperature}=    Convert To Number    ${temperature}  # Assurez-vous que c'est un nombre
    Température Doit ÊTre Valide    ${temperature}
    Log    Température validée avec succès: ${temperature}

Test Validation Température Hors Limite
    [Documentation]    Vérifie qu'une température hors limite (-20°C) est invalide.
    ${temperature}=    Set Variable    -20
    ${temperature}=    Convert To Number    ${temperature}  # Assurez-vous que c'est un nombre
    ${result}=    Is Valid Temperature    ${temperature}
    Should Be Equal As Numbers    ${result}    0    # 0 pour invalide
    Log    Température correctement détectée comme invalide: ${temperature}

Test Validation Température Hors Plage Positive
    [Documentation]    Vérifie qu'une température hors plage positive (150°C) est invalide.
    ${temperature}=    Set Variable    150
    ${temperature}=    Convert To Number    ${temperature}  # Assurez-vous que c'est un nombre
    ${result}=    Is Valid Temperature    ${temperature}
    Should Be Equal As Numbers    ${result}    0    # 0 pour invalide
    Log    Température correctement détectée comme invalide: ${temperature}
