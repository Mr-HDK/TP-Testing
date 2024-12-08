/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include "mock_temp_sensor.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_check_temperature_should_return_1_when_too_hot(void);
extern void test_check_temperature_should_return_minus_1_when_too_cold(void);
extern void test_check_temperature_should_return_0_when_normal(void);
extern void test_check_temperature_should_handle_exact_limits(void);
extern void test_check_temperature_should_handle_extreme_values(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_temp_sensor_Init();
}
static void CMock_Verify(void)
{
  mock_temp_sensor_Verify();
}
static void CMock_Destroy(void)
{
  mock_temp_sensor_Destroy();
}

/*=======Setup (stub)=====*/
void setUp(void) {}

/*=======Teardown (stub)=====*/
void tearDown(void) {}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_temp_controller.c");
  run_test(test_check_temperature_should_return_1_when_too_hot, "test_check_temperature_should_return_1_when_too_hot", 17);
  run_test(test_check_temperature_should_return_minus_1_when_too_cold, "test_check_temperature_should_return_minus_1_when_too_cold", 22);
  run_test(test_check_temperature_should_return_0_when_normal, "test_check_temperature_should_return_0_when_normal", 27);
  run_test(test_check_temperature_should_handle_exact_limits, "test_check_temperature_should_handle_exact_limits", 34);
  run_test(test_check_temperature_should_handle_extreme_values, "test_check_temperature_should_handle_extreme_values", 52);

  CMock_Guts_MemFreeFinal();
  return UnityEnd();
}
