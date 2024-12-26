*** Settings ***
Resource    ./resources/keywords.robot
Variables    ../src/config.py
Library     BuiltIn

*** Test Cases ***
Test Lecture Température Valide Avec Aléatoire
    [Documentation]    Vérifie qu'une température aléatoire générée est valide.
    ${temperature}=    Simuler Lecture Température
    Température Doit ÊTre Valide    ${temperature}
    Log    Température générée: ${temperature}

Test Lecture Température Valide Avec Valeur Fixe
    [Documentation]    Vérifie qu'une température fixe fournie est valide.
    ${temperature}=    Simuler Lecture Température    custom_value=25
    Température Doit ÊTre Valide    ${temperature}
    Log    Température définie: ${temperature}

Test Action Chauffage
    [Documentation]    Vérifie que le chauffage est activé pour une température basse.
    ${result}=    Tester Action Température    10
    Should Be Equal    ${result}    Heater activated
    Log    Action résultante: ${result}

Test Action Ventilateur
    [Documentation]    Vérifie que le ventilateur est activé pour une température élevée.
    ${result}=    Tester Action Température    40
    Should Be Equal    ${result}    Fan activated
    Log    Action résultante: ${result}

Test Notification Température Hors Plage
    [Documentation]    Vérifie l'envoi d'une notification pour une température hors de la plage valide.
    ${out_of_range_temp}=    Evaluate    ${MAX_TEMP_THRESHOLD} + 20
    Tester Notification Température Hors Plage    ${out_of_range_temp}
    Log    Notification vérifiée pour température hors plage: ${out_of_range_temp}

Test Température Critique
    [Documentation]    Vérifie la gestion des températures critiques en dehors de la plage normale.
    ${temperature}=    Evaluate    ${MIN_TEMP_THRESHOLD} - 10
    Run Keyword And Expect Error    Température non valide*    Température Doit ÊTre Valide    ${temperature}
    Log    Température critique détectée: ${temperature}