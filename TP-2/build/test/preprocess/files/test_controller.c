#include "src/utils.h"
#include "src/notifier.h"
#include "C:/Users/HP/TP-Testing/TP-2/vendor/ceedling/vendor/unity/src/unity.h"






void setUp(void) {}

void tearDown(void) {}



void test_notify_threshold_exceeded_triggers_alert(void) {

    int threshold_exceed_value = 120;





    FILE *temp_file = tmpfile();

    if (!temp_file) {

        UnityFail( (("Impossible de crer un fichier temporaire pour capturer stdout")), (UNITY_UINT)(17));

    }

    fflush(

          (&_iob[1])

                );

    int stdout_fd = dup(

                       (((&_iob[1]))->_file)

                                     );

    dup2(

        ((

        temp_file

        )->_file)

                         , 

                           (((&_iob[1]))->_file)

                                         );





    notify_threshold_exceeded(threshold_exceed_value);





    fflush(

          (&_iob[1])

                );

    dup2(stdout_fd, 

                   (((&_iob[1]))->_file)

                                 );

    close(stdout_fd);





    rewind(temp_file);

    char output_buffer[256] = {0};

    fread(output_buffer, sizeof(char), 255, temp_file);

    fclose(temp_file);





    do {if ((strstr(output_buffer, "ALERT: Value 120 exceeds the threshold!") != 

   ((void *)0)

   )) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(38)));}} while(0);

}



void test_notify_threshold_not_exceeded_does_not_trigger_alert(void) {

    int threshold_non_exceed_value = 80;





    FILE *temp_file = tmpfile();

    if (!temp_file) {

        UnityFail( (("Impossible de crer un fichier temporaire pour capturer stdout")), (UNITY_UINT)(47));

    }

    fflush(

          (&_iob[1])

                );

    int stdout_fd = dup(

                       (((&_iob[1]))->_file)

                                     );

    dup2(

        ((

        temp_file

        )->_file)

                         , 

                           (((&_iob[1]))->_file)

                                         );





    notify_threshold_exceeded(threshold_non_exceed_value);





    fflush(

          (&_iob[1])

                );

    dup2(stdout_fd, 

                   (((&_iob[1]))->_file)

                                 );

    close(stdout_fd);





    rewind(temp_file);

    char output_buffer[256] = {0};

    fread(output_buffer, sizeof(char), 255, temp_file);

    fclose(temp_file);





    UnityAssertEqualString((const char*)(("")), (const char*)((output_buffer)), (

   ((void *)0)

   ), (UNITY_UINT)(68));

}
