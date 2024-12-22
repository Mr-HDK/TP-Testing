*** Settings ***
Suite Setup    Log    Début des tests globaux
Suite Teardown    Log    Fin des tests globaux

*** Test Cases ***
Exécuter Tests Fonctionnels
    Run Tests From Suite    functional_tests.robot

Exécuter Tests de Validation
    Run Tests From Suite    validation_tests.robot

Exécuter Tests d'Alerte
    Run Tests From Suite    alert_tests.robot

Exécuter Tests E2E
    Run Tests From Suite    test_e2e_45.robot
    Run Tests From Suite    test_temperature_critical.robot
