#include "src/sensor.h"
#include "C:/Ruby30-x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {}

void tearDown(void) {}





void test_read_sensor_returns_within_expected_range(void) {

    for (int i = 0; i < 100; i++) {

        int value = read_sensor();

        do {if ((value >= 0 && value < 150)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(11)));}} while(0);

    }

}



void test_is_valid_value_identifies_correct_boundaries(void) {

    do {if ((is_valid_value(50))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(16)));}} while(0);

    do {if ((is_valid_value(0))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(17)));}} while(0);

    do {if ((is_valid_value(100))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(18)));}} while(0);

    do {if (!(is_valid_value(-1))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(19)));}} while(0);

    do {if (!(is_valid_value(101))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(20)));}} while(0);

}
