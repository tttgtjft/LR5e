#include <assert.h>
#include "../tasks/tasks_.h"
#include "../string_.h"

void test_task1_removeNonLetters_withoutSpace() {
    char s[MAX_STRING_SIZE] = "kurapika";

    task1_removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_task1_removeNonLetters_withSpace() {
    char s[MAX_STRING_SIZE] = "k u\tr a p i\r\tk a";

    task1_removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_task1_removeNonLetters_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    task1_removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_task1_removeNonLetters_allSpaceSymbols() {
    char s[MAX_STRING_SIZE] = "\t \n \n \t";

    task1_removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_task2_removeNonLetters() {
    test_task1_removeNonLetters_withoutSpace();
    test_task1_removeNonLetters_withSpace();
    test_task1_removeNonLetters_emptyString();
    test_task1_removeNonLetters_allSpaceSymbols();

}



void test_task2_removeExtraSpaces_stringWithSpaces() {
    char s[MAX_STRING_SIZE] = " k ura pi k a ";

    task2_removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " k ura pi k a ";

    assert(strcmp(s, expectation) == 0);
}

void test_task2_removeExtraSpaces_stringWithoutSpaces() {
    char s[MAX_STRING_SIZE] = "kurapika";

    task2_removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_task2_removeExtraSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    task2_removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_task2_removeExtraSpaces_allSpaces() {
    char s[MAX_STRING_SIZE] = " ";

    task2_removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " ";

    assert(strcmp(s, expectation) == 0);
}

void test_task2_removeExtraSpaces() {
    test_task2_removeExtraSpaces_stringWithSpaces();
    test_task2_removeExtraSpaces_stringWithoutSpaces();
    test_task2_removeExtraSpaces_emptyString();
    test_task2_removeExtraSpaces_stringWithSpaces();
    test_task2_removeExtraSpaces_allSpaces();
}



void test_task4_replaceDigitsWithSpaces_stringWithDigits() {
    char s[MAX_STRING_SIZE] = "kur3apik1a";

    task4_replaceDigitsWithSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kur   apik a";

    assert(strcmp(s, expectation) == 0);
}

void test_task4_replaceDigitsWithSpaces_stringWithoutDigit() {

}

void test_task4_replaceDigitsWithSpaces_allDigit() {

}

void test_task4_replaceDigitsWithSpaces_emptyString() {

}

void test_task4_replaceDigitsWithSpaces() {
    test_task4_replaceDigitsWithSpaces_stringWithDigits();
    test_task4_replaceDigitsWithSpaces_stringWithoutDigit();
    test_task4_replaceDigitsWithSpaces_allDigit();
    test_task4_replaceDigitsWithSpaces_emptyString();
}

void test_tasks() {
    test_task2_removeNonLetters();
    test_task2_removeExtraSpaces();
    test_task4_replaceDigitsWithSpaces();
}