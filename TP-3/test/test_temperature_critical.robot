*** Settings ***
Resource    ../test/resources/keywords.robot  # Contient les mots-clés nécessaires
Library     BuiltIn
Library     OperatingSystem  # Pour gérer les logs
Library     ../src/utils.py  # Inclut les fonctions de validation et les seuils

*** Variables ***
${TEMP_CRITIQUE}    120  # Température critique définie

*** Test Cases ***
Scénario: Gestion d'une température critique et d'une alerte
    [Documentation]    Ce test valide le comportement du système lorsqu'une température dépasse les seuils définis.
    [Tags]    temperature    critique    e2e

    # Étape 1 : Fixer la température à 120°C
    Log To Console    *** DÉBUT DU TEST: Fixation de la température ***
    Log    Fixation de la température à ${TEMP_CRITIQUE}°C
    Set Temperature    ${TEMP_CRITIQUE}    # Assurez-vous que ce mot-clé est bien défini et fonctionne correctement

    # Étape 2 : Vérifier que la température est invalide
    Log    Vérification que la température est invalide
    ${is_valid}=   Is Valid Temperature    ${TEMP_CRITIQUE}   # Vérifiez la fonction de validation
    Log    La validation de la température retourne: ${is_valid}
    Should Not Be True    ${is_valid}    La température ${TEMP_CRITIQUE}°C ne devrait pas être considérée comme valide !

    # Étape 3 : Vérifier qu'aucune action n'est prise (chauffage ou ventilateur)
    Log    Vérification qu'aucune action n'est prise (chauffage ou ventilateur)
    ${action_taken}=    Check Actions  # Ce mot-clé doit vérifier si aucune action n'a été prise
    Should Not Be True    ${action_taken}    Aucune action ne devrait être prise pour une température critique !

    # Étape 4 : Vérifier qu'une notification critique est envoyée
    Log    Vérification de l'envoi d'une notification critique
    ${notification_sent}=    Send Notification    Température critique détectée: ${TEMP_CRITIQUE}°C
    Should Be True    ${notification_sent}    Une notification devrait être envoyée pour une température critique !

    # Étape 5 : Log détaillé pour documenter chaque étape
    Log    Toutes les vérifications ont été effectuées avec succès.

    Log To Console    *** FIN DU TEST: Gestion d'une température critique ***
