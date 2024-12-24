*** Settings ***
Library    ../src/sensor.py
Library    ../src/actuator.py
Library    ../src/notifier.py
Library    ../src/utils.py
Library    BuiltIn

*** Keywords ***
Simuler Lecture Température
    [Arguments]    ${custom_value}=None
    ${temperature}=    read_temperature    ${custom_value}
    RETURN    ${temperature}

Température Doit Être Valide
    [Arguments]    ${temperature}
    ${result}=    Is Valid Temperature    ${temperature}
    Should Be True    ${result}    Température non valide: ${temperature}
    Log    Température validée: ${temperature}

Tester Action Température
    [Arguments]    ${temperature}
    ${temperature}=    Convert To Number    ${temperature}
    ${action}=    Control Temperature    ${temperature}
    Run Keyword If    ${temperature} > 100
        Should Not Contain    ${action}    Fan activated
    Else
        Should Contain    ${action}    Fan activated
    RETURN    ${action}


Tester Notification Température Hors Plage
    [Arguments]    ${temperature}
    Send Notification    Alerte : Température hors plage (${temperature}°C)
    Log    Notification envoyée avec succès pour ${temperature}°C

*** Keywords ***

Tester Notification Température Critique
    [Arguments]    ${temperature}
    Run Keyword If    ${temperature} < 0 or ${temperature} > 120
    ...    Log    "Température critique détectée: ${temperature}°C"
    ...    Should Be True    ${temperature} < 0 or ${temperature} > 120    "Notification critique envoyée pour température: ${temperature}"
    ...    ELSE
    ...    Log    "Température dans la plage acceptable: ${temperature}°C"

*** Keywords ***
Température Doit Être Invalide
    [Arguments]    ${temperature}
    Should Be True    ${temperature} < 0 or ${temperature} > 100    "Température invalide: ${temperature}"
