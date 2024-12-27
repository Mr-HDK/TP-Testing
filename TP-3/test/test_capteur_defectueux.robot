*** Settings ***
Resource    resources/keywords.robot
Library     BuiltIn

*** Variables ***
${VALID_TEMPERATURE}    25
${INVALID_TEMPERATURE}  None

*** Test Cases ***
Test Capteur Défectueux
    [Documentation]    Ce test vérifie que le système gère un capteur défectueux (None ou température hors plage).
    ${result} =    Simuler Capteur Défectueux    ${INVALID_TEMPERATURE}
    Should Be Equal    ${result}    ${INVALID_TEMPERATURE}
    Log    Capteur défectueux ou température invalide détectée.

Test Capteur Valide
    [Documentation]    Ce test vérifie que le système gère une température valide.
    ${result} =    Simuler Capteur Valide    ${VALID_TEMPERATURE}
    Should Be Equal    ${result}    ${VALID_TEMPERATURE}
    Log    Capteur valide détecté avec succès.
