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
    Run Keyword If    '${temperature}' == ''    Fail    Lecture de la température a échoué
    RETURN    ${temperature}

Température Doit ÊTre Valide
    [Arguments]    ${temperature}
    ${result}=    Is Valid Temperature    ${temperature}
    Should Be True    ${result}    Température non valide: ${temperature}
    Log    Température validée: ${temperature}

Tester Action Température
    [Arguments]    ${temperature}
    ${temperature}=    Convert To Number    ${temperature}
    Run Keyword If    ${temperature} < -50    Fail    Température trop basse: ${temperature}
    Run Keyword If    ${temperature} > 150    Fail    Température trop élevée: ${temperature}
    ${action}=    Control Temperature    ${temperature}
    RETURN    ${action}

Tester Notification Température Hors Plage
    [Arguments]    ${temperature}
    Run Keyword If    ${temperature} < -50 or ${temperature} > 150    Send Notification    Alerte : Température hors plage (${temperature}°C)
    Log    Notification envoyée avec succès pour ${temperature}°C
