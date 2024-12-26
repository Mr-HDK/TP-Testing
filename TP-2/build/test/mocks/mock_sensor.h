/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_SENSOR_H
#define _MOCK_SENSOR_H

#include "unity.h"
#include "sensor.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_sensor_Init(void);
void mock_sensor_Destroy(void);
void mock_sensor_Verify(void);




#define read_sensor_IgnoreAndReturn(cmock_retval) read_sensor_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void read_sensor_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define read_sensor_StopIgnore() read_sensor_CMockStopIgnore()
void read_sensor_CMockStopIgnore(void);
#define read_sensor_ExpectAndReturn(cmock_retval) read_sensor_CMockExpectAndReturn(__LINE__, cmock_retval)
void read_sensor_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
typedef int (* CMOCK_read_sensor_CALLBACK)(int cmock_num_calls);
void read_sensor_AddCallback(CMOCK_read_sensor_CALLBACK Callback);
void read_sensor_Stub(CMOCK_read_sensor_CALLBACK Callback);
#define read_sensor_StubWithCallback read_sensor_Stub
#define is_valid_value_IgnoreAndReturn(cmock_retval) is_valid_value_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void is_valid_value_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return);
#define is_valid_value_StopIgnore() is_valid_value_CMockStopIgnore()
void is_valid_value_CMockStopIgnore(void);
#define is_valid_value_ExpectAndReturn(value, cmock_retval) is_valid_value_CMockExpectAndReturn(__LINE__, value, cmock_retval)
void is_valid_value_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int value, _Bool cmock_to_return);
typedef _Bool (* CMOCK_is_valid_value_CALLBACK)(int value, int cmock_num_calls);
void is_valid_value_AddCallback(CMOCK_is_valid_value_CALLBACK Callback);
void is_valid_value_Stub(CMOCK_is_valid_value_CALLBACK Callback);
#define is_valid_value_StubWithCallback is_valid_value_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
