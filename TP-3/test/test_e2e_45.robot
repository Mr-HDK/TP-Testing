*** Settings ***
Resource    ./resources/keywords.robot
Library     BuiltIn

*** Variables ***
${valid_temperatures}    create list    25    30    50    80
${invalid_temperatures}  create list    -10    110    150

*** Test Cases ***
Test Lecture Température Valide
    [Template]  Loop Through
    [Arguments]  ${valid_temperatures}
    ${temperature}=  Set Variable  ${item}
    Température Doit ÊTre Valide  ${temperature}
    Log  Température générée: ${temperature}

Test Lecture Température Invalide
    [Template]  Loop Through
    [Arguments]  ${invalid_temperatures}
    ${temperature}=  Set Variable  ${item}
    Température Doit ÊTre Invalide  ${temperature}  # Add this keyword
    Log  Température générée: ${temperature} 

# ... other tests ...