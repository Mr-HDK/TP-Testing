*** Settings ***
Documentation     Test de gestion d'une température critique (120°C)
...               Vérifie que le système :
...               - Détecte une température invalide
...               - N'active ni chauffage ni ventilation
...               - Envoie une notification critique
Resource          resources/keywords.robot
Library           BuiltIn

*** Variables ***
${TEMP_CRITIQUE}    120

*** Test Cases ***
Test Gestion Température Critique
    [Documentation]    Vérifie le comportement du système avec une température critique de 120°C
    
    # Étape 1: Simulation d'une température critique
    Log    Étape 1: Simulation d'une température de ${TEMP_CRITIQUE}°C
    ${temperature}=    Simuler Lecture Température    ${TEMP_CRITIQUE}
    
    # Étape 2: Validation que la température est invalide
    Log    Étape 2: Vérification que la température est invalide
    Run Keyword And Expect Error    *La température ${TEMP_CRITIQUE}*n'est pas dans la plage valide*    
    ...    Température Doit Être Valide    ${temperature}
    
    # Étape 3: Vérification qu'aucune action n'est prise
    Log    Étape 3: Vérification qu'aucune action n'est prise
    ${result}=    Tester Action Température    ${temperature}
    Should Be Equal    ${result}    No action    
    ...    msg=Une action incorrecte a été prise alors que la température est critique
    
    # Étape 4: Vérification de l'envoi d'une notification
    Log    Étape 4: Vérification de l'envoi d'une notification critique
    ${status}=    Tester Notification Température Hors Plage    ${temperature}
    Should Be True    ${status}    
    ...    msg=Aucune notification n'a été envoyée pour la température critique

*** Keywords ***
Log Step Result
    [Arguments]    ${step_number}    ${description}    ${result}
    Log    Step ${step_number}: ${description} - Résultat: ${result}