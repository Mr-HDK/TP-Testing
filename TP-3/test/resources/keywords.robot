*** Settings ***
Library    BuiltIn
Library    ${EXECDIR}/src/sensor.py    WITH NAME    Sensor
Library    ${EXECDIR}/src/actuator.py    WITH NAME    Actuator
Library    ${EXECDIR}/src/notifier.py    WITH NAME    Notifier
Library    ${EXECDIR}/src/controller.py    WITH NAME    Controller

*** Variables ***
${TEMP_MIN}    0
${TEMP_MAX}    100

*** Keywords ***
Simuler Lecture Température
    [Arguments]    ${custom_value}=${NONE}
    IF    "${custom_value}" == "${NONE}"
        ${temperature}=    Sensor.Read Temperature
    ELSE
        ${temperature}=    Sensor.Read Temperature    ${custom_value}
    END
    ${temperature}=    Convert To Number    ${temperature}
    RETURN    ${temperature}

Température Doit Être Valide
    [Arguments]    ${temperature}
    ${temp_float}=    Convert To Number    ${temperature}
    Should Be True    ${TEMP_MIN} <= ${temp_float} <= ${TEMP_MAX}
    ...    msg=La température ${temperature} n'est pas dans la plage valide [${TEMP_MIN}, ${TEMP_MAX}]

Tester Action Température
    [Arguments]    ${temperature}
    ${temp_float}=    Convert To Number    ${temperature}
    ${result}=    Controller.Process Temperature    ${temp_float}
    # Extraire uniquement le message d'action
    ${action}=    Set Variable    ${result}[1]
    RETURN    ${action}

Tester Notification Température Hors Plage
    [Arguments]    ${temperature}
    ${temp_float}=    Convert To Number    ${temperature}
    ${message}=    Set Variable    Température hors plage détectée: ${temp_float}°C
    Run Keyword    Notifier.Send Notification    ${message}
    RETURN    ${TRUE}