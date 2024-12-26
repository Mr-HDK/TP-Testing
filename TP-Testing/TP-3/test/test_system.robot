*** Settings ***
Resource    resources/keywords.robot
Library     BuiltIn

*** Test Cases ***
Test Lecture Température Valide Avec Aléatoire
    ${temperature}=    Simuler Lecture Température
    Température Doit Être Valide    ${temperature}
    Should Be True    0 <= ${temperature} <= 100    # Ajout d'une validation de plage
    Log    Température générée: ${temperature}

Test Lecture Température Valide Avec Valeur Fixe
    ${temperature}=    Simuler Lecture Température    25
    Température Doit Être Valide    ${temperature}
    Should Be Equal    ${temperature}    ${25.0}    # Validation plus précise
    Log    Température définie: ${temperature}

Test Action Chauffage
    ${result}=    Tester Action Température    10
    Should Be Equal    ${result}    Heater activated
    Log    Action chauffage vérifiée pour température: 10°C

Test Action Ventilateur
    ${result}=    Tester Action Température    40
    Should Be Equal    ${result}    Fan activated
    Log    Action ventilateur vérifiée pour température: 40°C

Test Notification Température Hors Plage
    ${out_of_range_temp}=    Set Variable    120    # Utilisation de Set Variable au lieu de Evaluate
    Tester Notification Température Hors Plage    ${out_of_range_temp}
    Log    Test notification effectué pour température: ${out_of_range_temp}°C

Test Température Critique
    [Documentation]    Vérifie la gestion des températures critiques.
    ${temperature}=    Set Variable    -10    # Utilisation de Set Variable
    Run Keyword And Expect Error    *    Température Doit Être Valide    ${temperature}    # On s'attend à une erreur
    Log    Test température critique effectué pour: ${temperature}°C