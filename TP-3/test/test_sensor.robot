*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn

*** Test Cases ***

Test Lecture Température None
    [Documentation]    Vérifie que le système gère correctement une valeur None.
    ${temperature}=    Simuler Lecture Température    None
    ${result}=    Process Temperature    ${temperature}
    Should Be Equal    ${result}    No action
    Log    Température None ignorée correctement.

Test Lecture Température Hors Plage Basse
    [Documentation]    Vérifie que le système ignore une température hors plage basse.
    ${temperature}=    Simuler Lecture Température    -100
    ${result}=    Process Temperature    ${temperature}
    Should Be Equal    ${result}    No action
    Log    Température hors plage basse ignorée correctement.

Test Lecture Température Hors Plage Haute
    [Documentation]    Vérifie que le système ignore une température hors plage haute.
    ${temperature}=    Simuler Lecture Température    150
    ${result}=    Process Temperature    ${temperature}
    Should Be Equal    ${result}    No action
    Log    Température hors plage haute ignorée correctement.

Test Log Température Hors Plage
    [Documentation]    Vérifie que le système logue correctement une température hors plage.
    ${temperature}=    Simuler Lecture Température    -50
    Process Temperature    ${temperature}
    Log Température Défectueuse    ${temperature}
    Log    Vérification de log effectuée avec succès pour ${temperature}.

