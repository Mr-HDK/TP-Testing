*** Settings ***
*** Settings ***
Library    C:\\Users\\eyama\\TP-Testing\\TP-3\\src\\sensor.py
Library    C:\\Users\\eyama\\TP-Testing\\TP-3\\src\\actuator.py
Library    C:\\Users\\eyama\\TP-Testing\\TP-3\\src\\notifier.py
Library    C:\\Users\\eyama\\TP-Testing\\TP-3\\src\\utils.py
Library    BuiltIn

*** Keywords ***
Simuler Lecture Température
    [Arguments]    ${custom_value}=None
    ${temperature}=    read_temperature    ${custom_value}
    RETURN    ${temperature}

Température Doit ÊTre Valide
    [Arguments]    ${temperature}
    ${result}=    Is Valid Temperature    ${temperature}
    Should Be True    ${result}    Température non valide: ${temperature}
    Log    Température validée: ${temperature}

Tester Action Température
    [Arguments]    ${temperature}
    ${temperature}=    Convert To Number    ${temperature}
    ${action}=    Control Temperature    ${temperature}
    RETURN    ${action}

Tester Notification Température Hors Plage
    [Arguments]    ${temperature}
    Send Notification    Alerte : Température hors plage (${temperature}°C)
    Log    Notification envoyée avec succès pour ${temperature}°C
