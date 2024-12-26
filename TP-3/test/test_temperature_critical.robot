*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn

*** Test Cases ***
Test Critical Temperature
    [Documentation]  Verifies behavior for a critical temperature.
    ${critical_temp}=  Set Variable  120  
    ${result}=  Tester Action Température  ${critical_temp}

    # Assertions for no action taken
    Should Not Be Equal  ${result}  Heater activated
    Should Not Be Equal  ${result}  Fan activated

    # Verify specific error message or notification content
    Should Contain  ${result}  "Critical temperature: ${critical_temp}" 

    # Log the result for better readability
    Log To Console  "Test result: ${result}"