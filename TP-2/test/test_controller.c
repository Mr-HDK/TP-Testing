#include "unity.h"
#include "notifier.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_notify_threshold_exceeded_triggers_alert(void) {
    int threshold_exceed_value = 120;

    // Redirection de stdout vers un fichier temporaire
    FILE *temp_file = tmpfile();
    if (!temp_file) {
        TEST_FAIL_MESSAGE("Impossible de créer un fichier temporaire pour capturer stdout");
    }
    fflush(stdout);
    int stdout_fd = dup(fileno(stdout));
    dup2(fileno(temp_file), fileno(stdout));

    // Exécution de la fonction à tester
    notify_threshold_exceeded(threshold_exceed_value);

    // Restauration de stdout
    fflush(stdout);
    dup2(stdout_fd, fileno(stdout));
    close(stdout_fd);

    // Lecture de la sortie capturée
    rewind(temp_file);
    char output_buffer[256] = {0};
    fread(output_buffer, sizeof(char), 255, temp_file);
    fclose(temp_file);

    // Vérifier que le message d'alerte attendu est dans la sortie capturée
    TEST_ASSERT_TRUE(strstr(output_buffer, "ALERT: Value 120 exceeds the threshold!") != NULL);
}

void test_notify_threshold_not_exceeded_does_not_trigger_alert(void) {
    int threshold_non_exceed_value = 80;

    // Redirection de stdout vers un fichier temporaire
    FILE *temp_file = tmpfile();
    if (!temp_file) {
        TEST_FAIL_MESSAGE("Impossible de créer un fichier temporaire pour capturer stdout");
    }
    fflush(stdout);
    int stdout_fd = dup(fileno(stdout));
    dup2(fileno(temp_file), fileno(stdout));

    // Exécution de la fonction à tester
    notify_threshold_exceeded(threshold_non_exceed_value);

    // Restauration de stdout
    fflush(stdout);
    dup2(stdout_fd, fileno(stdout));
    close(stdout_fd);

    // Lecture de la sortie capturée
    rewind(temp_file);
    char output_buffer[256] = {0};
    fread(output_buffer, sizeof(char), 255, temp_file);
    fclose(temp_file);

    // Vérifier que le buffer est vide, donc aucun message d'alerte
    TEST_ASSERT_EQUAL_STRING("", output_buffer);
}
