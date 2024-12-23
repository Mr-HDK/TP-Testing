*** Settings ***
Resource    ../resources/keywords.robot
Library     BuiltIn

*** Test Cases ***
Test Lecture Température Valide Avec Aléatoire
    ${temperature}=    Simuler Lecture Température
    Température Doit ÊTre Valide    ${temperature}
    Log    Température générée: ${temperature}

Test Lecture Température Valide Avec Valeur Fixe
    ${temperature}=    Simuler Lecture Température    25
    Température Doit ÊTre Valide    ${temperature}
    Log    Température définie: ${temperature}

Test Action Chauffage
    ${result}=    Tester Action Température    10
    Should Be Equal    ${result}    Heater activated

Test Action Ventilateur
    ${result}=    Tester Action Température    40
    Should Be Equal    ${result}    Fan activated

Test Notification Température Hors Plage
    ${out_of_range_temp}=    Evaluate    120
    Tester Notification Température Hors Plage    ${out_of_range_temp}

Test Température Critique
    [Documentation]    Vérifie la gestion des températures critiques.
    ${temperature}=    Simuler Lecture Température    -10
    Température Doit ÊTre Valide    ${temperature}

