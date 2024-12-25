*** Settings ***
Library    ../../src/sensor.py
Library    ../../src/actuator.py
Library    ../../src/notifier.py
Library    ../../src/utils.py
Library    BuiltIn

*** Keywords ***
Simuler Lecture Température
    [Arguments]    ${custom_value}=None
    ${temperature}=    read_temperature    ${custom_value}
    RETURN    ${temperature}

Température Doit Être valide
    [Arguments]    ${temperature}
    ${valid}=    Is Valid Temperature    ${temperature}
    Should Be True    ${valid}    La température ${temperature} devrait être valide.

Tester Action Température
    [Arguments]    ${temperature}
    ${temperature}=    Convert To Number    ${temperature}
    ${action}=    Control Temperature    ${temperature}
    RETURN    ${action}

*** Keywords ***
Tester Notification Température Hors Plage
    [Arguments]    ${temperature}
    Send Notification    Alerte : Température hors plage (${temperature}°C)
    Log    Notification envoyée avec succès pour ${temperature}°C


*** Keywords ***
Vérifier Qu'Aucune Action N'Est Prise
    [Arguments]    ${temperature}
    Run Keyword And Return Status    Should Be Equal    ${temperature}    None
    Log    Aucune action prise pour une température critique.

Vérifier Qu'Une Notification Critique Est Envoyée
    [Arguments]    ${temperature}
    Run Keyword If    ${temperature} > 100    Tester Notification Température Hors Plage    ${temperature}
    Log    Température critique détectée : ${temperature}


*** Keywords ***
Simuler Capteur Défectueux
    [Arguments]    ${temperature}
    Log    Simulation capteur défectueux avec température : ${temperature}
    RETURN    ${temperature}

Simuler Capteur Valide
    [Arguments]    ${temperature}
    Log    Simulation capteur valide avec température : ${temperature}
    RETURN    ${temperature}

Température Est Valide
    [Arguments]    ${temperature}
    [Documentation]    Vérifie si la température est valide (ni None, ni hors plage).
    ${is_valid} =    Evaluate    -40 <= ${temperature} <= 120 if ${temperature} is not None else False
    Log    Température est valide : ${is_valid}
    RETURN    ${is_valid}
