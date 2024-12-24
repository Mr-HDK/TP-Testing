*** Settings ***
Library    ../../src/sensor.py
Library    ../../src/actuator.py
Library    ../../src/notifier.py
Library    ../../src/utils.py
Library    ../../src/config.py
Library    ../../src/sensor.py
Library    BuiltIn

*** Keywords ***
Simuler Lecture Température
    [Arguments]    ${custom_value}=None
    ${temperature}=    read_temperature    ${custom_value}
    RETURN    ${temperature}
Test Capteur Défectueux
    # Simulate a defective sensor that returns None or an out-of-range value like -100°C
    ${temperature}=    Simuler Lecture Température
    Run Keyword If    '${temperature}' == 'None'    Log    Erreur: Capteur défectueux, valeur de température inconnue
    Run Keyword If    '${temperature}' == '-100.0'    Log    Erreur: Température hors plage détectée: ${temperature}
    Run Keyword If    '${temperature}' != 'None' and '${temperature}' != '-100.0'    Log    Température valide: ${temperature}
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

Is Valid Temperature
    [Arguments]    ${temperature}
    # Convert the temperature argument to an integer if it's a string or float
    ${temperature}=    Convert To Integer    ${temperature}
    
    # Directly access the values from the imported config.py
    ${min_temp}=    Get Variable Value    ${MIN_TEMP_THRESHOLD}    -10  # Default to 0 if not set
    ${max_temp}=    Get Variable Value    ${MAX_TEMP_THRESHOLD}    100  # Default to 100 if not set
    
    # Log the retrieved thresholds for debugging purposes
    Log    Seuils de température : ${min_temp} à ${max_temp}
    
    # Evaluate if the temperature is within the valid range
    ${valid}=    Evaluate    ${temperature} >= ${min_temp} and ${temperature} <= ${max_temp}
    
    # Return the result
    [Return]    ${valid}

Send Notification
    [Arguments]    ${message}
    Log    Envoi de notification: ${message}
    ${notification_sent}=    SendAlert    ${message}  # Assuming `SendAlert` is implemented in `notifier.py`
    [Return]    ${notification_sent}

Check Actions
    Log    Vérification des actions système (chauffage, ventilateur)
    ${actions}=    CheckSystemActions  # Assuming `CheckSystemActions` is defined in `actuator.py` or relevant file
    [Return]    ${actions}

Set Temperature
    [Arguments]    ${temperature}
    Log    Réglage de la température à ${temperature}°C
    # Ajoutez ici la logique pour définir la température dans votre système, par exemple:
    # temperature = set_temperature_in_system(${temperature})
