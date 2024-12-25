*** Settings *** 
Resource    ./resources/keywords.robot
Library     BuiltIn

*** Variables ***
${TEMP_CRITIQUE}    120
${NO_ACTION}        No action

*** Test Cases ***
Gestion D'une Température Critique Et D'une Alerte
    [Documentation]    Teste la gestion d'une température critique et l'envoi d'une notification d'alerte.
    
    # Étape 1 : Fixer la température critique
    Log    Début du test pour la gestion d'une température critique.
    ${temperature}=    Set Variable    ${TEMP_CRITIQUE}
    Log    Température fixée à ${temperature}°C pour le test.

    # Étape 2 : Valider que la température est invalide
    Log    Vérification que la température ${temperature}°C est considérée comme invalide.
    ${is_valid}=    Run Keyword And Return Status    Température Doit ÊTre Valide    ${temperature}
    Should Be Equal    ${is_valid}    ${False}    La température ${temperature}°C a été incorrectement validée comme valide.
    Log    Validation réussie : la température ${temperature}°C est effectivement non valide.

    # Étape 3 : Vérifier qu'aucune action (chauffage ou ventilation) n'est prise
    Log    Vérification qu'aucune action n'est entreprise pour une température critique.
    ${action}=    Tester Action Température    ${temperature}
    Should Be Equal    ${action}    ${NO_ACTION}    Une action a été prise pour une température critique : ${action}.
    Log    Aucune action prise pour la température ${temperature}°C, comme attendu.

    # Étape 4 : Vérifier qu'une notification est envoyée pour la température critique
    Log    Vérification qu'une notification est envoyée pour alerter d'une température critique.
    Tester Notification Température Hors Plage    ${temperature}
    Log    Notification envoyée correctement pour la température critique : ${temperature}°C.

    # Étape 5 : Ajouter des logs pour documenter chaque étape
    Log    Test terminé avec succès pour la gestion d'une température critique et l'envoi d'une alerte.
