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

    // Capture de la sortie vers un buffer
    char output_buffer[256];
    setbuf(stdout, output_buffer); // Redirige stdout vers output_buffer

    // Exécution de la fonction à tester
    notify_threshold_exceeded(threshold_exceed_value);

    // Vérifier que le message d'alerte attendu est dans le buffer
    // Nous recherchons uniquement la partie "ALERT: Value 120 exceeds the threshold!"
    TEST_ASSERT_TRUE(strstr(output_buffer, "ALERT: Value 120 exceeds the threshold!") != NULL);
}

void test_notify_threshold_not_exceeded_does_not_trigger_alert(void) {
    int threshold_non_exceed_value = 80;

    // Capture de la sortie vers un buffer
    char output_buffer[256];
    setbuf(stdout, output_buffer); // Redirige stdout vers output_buffer

    // Exécution de la fonction à tester
    notify_threshold_exceeded(threshold_non_exceed_value);

    // Vérifier que le buffer est vide, donc aucun message d'alerte
    TEST_ASSERT_EQUAL_STRING("", output_buffer);
}
