#include <assert.h>
#include "../tasks/tasks_.h"
#include "../string_.h"

#include <stdio.h>
void test_task1_removeNonLetters_withoutSpace() {
    char s[MAX_STRING_SIZE] = "kurapika";

    task1_removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_task1_removeNonLetters_withSpace() {
    char s[MAX_STRING_SIZE] = "k u\tr a p i\r\tk a";

    task1_removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_task1_removeNonLetters_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    task1_removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task1_removeNonLetters_allSpaceSymbols() {
    char s[MAX_STRING_SIZE] = "\t \n \n \t";

    task1_removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task1_removeNonLetters() {
    test_task1_removeNonLetters_withoutSpace();
    test_task1_removeNonLetters_withSpace();
    test_task1_removeNonLetters_emptyString();
    test_task1_removeNonLetters_allSpaceSymbols();
}

void test_task2_removeExtraSpaces_stringWithSpaces() {
    char s[MAX_STRING_SIZE] = " k ura pi k a ";

    task2_removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " k ura pi k a ";

    assert(strcmp_(s, expectation) == 0);
}

void test_task2_removeExtraSpaces_stringWithoutSpaces() {
    char s[MAX_STRING_SIZE] = "kurapika";

    task2_removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_task2_removeExtraSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    task2_removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task2_removeExtraSpaces_allSpaces() {
    char s[MAX_STRING_SIZE] = " ";

    task2_removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " ";

    assert(strcmp_(s, expectation) == 0);
}

void test_task2_removeExtraSpaces() {
    test_task2_removeExtraSpaces_stringWithSpaces();
    test_task2_removeExtraSpaces_stringWithoutSpaces();
    test_task2_removeExtraSpaces_emptyString();
    test_task2_removeExtraSpaces_stringWithSpaces();
    test_task2_removeExtraSpaces_allSpaces();
}

void test_task3_reverseLettersOfWordsOfString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    task3_reverseLettersOfWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task3_reverseLettersOfWordsOfString_oneWord() {
    char *s = "kurapika";

    task3_reverseLettersOfWordsOfString(s);
    printf("%s", s);

    char expectation[MAX_STRING_SIZE] = "akiparuk";

    assert(strcmp_(s, expectation) == 0);
}

void test_task3_reverseLettersOfWordsOfString_fewWords() {
    char *s = "kurapika BEST BOY";

    task3_reverseLettersOfWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "akiparuk TSEB YOB";

    assert(strcmp_(s, expectation) == 0);
}

void test_task3_reverseLettersOfWordsOfString() {
    //test_task3_reverseLettersOfWordsOfString_emptyString();
    //test_task3_reverseLettersOfWordsOfString_oneWord();
    //test_task3_reverseLettersOfWordsOfString_fewWords();
}

void test_task4_replaceDigitsWithSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    task4_replaceDigitsWithSpaces(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task4_replaceDigitsWithSpaces_stringWithoutDigit() {
    char s[MAX_STRING_SIZE] = "kurapika";

    task4_replaceDigitsWithSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_task4_replaceDigitsWithSpaces_stringWithDigits() {
    char s[MAX_STRING_SIZE] = "kur3apik1a";

    task4_replaceDigitsWithSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kur   apik a";

    assert(strcmp_(s, expectation) == 0);
}

void test_task4_replaceDigitsWithSpaces_allDigit() {
    char s[MAX_STRING_SIZE] = "42";

    task4_replaceDigitsWithSpaces(s);

    char expectation[MAX_STRING_SIZE] = "      ";

    assert(strcmp_(s, expectation) == 0);
}

void test_task4_replaceDigitsWithSpaces() {
    test_task4_replaceDigitsWithSpaces_emptyString();
    test_task4_replaceDigitsWithSpaces_stringWithoutDigit();
    test_task4_replaceDigitsWithSpaces_stringWithDigits();
    test_task4_replaceDigitsWithSpaces_allDigit();
}



void test_task5_replace_emptyString() {
    char w1[MAX_STRING_SIZE] = "kurapika";
    char w2[MAX_STRING_SIZE] = "emo boy";

    char s[MAX_STRING_SIZE] = "";

    task5_replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task5_replace_oneLetter() {
    char s[MAX_STRING_SIZE] = "kurapi ka";
    char w1[MAX_STRING_SIZE] = "ka";
    char w2[MAX_STRING_SIZE] = "a";

    task5_replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "kurapi a ";

    assert(strcmp_(s, expectation) == 0);
}

void test_task5_replace_oneWord() {
    char s[MAX_STRING_SIZE] = "kur a pik a";
    char w1[MAX_STRING_SIZE] = "a";
    char w2[MAX_STRING_SIZE] = "pico";

    task5_replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "kur pico pik pico";

    assert(strcmp_(s, expectation) == 0);
}

void test_task5_replace() {
    test_task5_replace_emptyString();
    test_task5_replace_oneLetter();
    test_task5_replace_oneWord();
}

void test_tasks() {
    test_task1_removeNonLetters();
    test_task2_removeExtraSpaces();
    //test_reverseLettersOfWordsOfString();
    test_task4_replaceDigitsWithSpaces();
    test_task5_replace();
}