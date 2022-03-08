#ifndef LR5E_TASKS__H
#define LR5E_TASKS__H

#include "../string_.h"

typedef struct wordDescriptor {
    char *begin;
    char *end;
} wordDescriptor;

void task1_removeNonLetters(char *s);

void task2_removeExtraSpaces(char *s);

void task3_reverseLettersOfWordsOfString(char *s);

void task4_replaceDigitsWithSpaces(char *s);

void task5_replace(char *source, char *w1, char *w2);

bool task6_areWordsOfStringLexicographicallyOrdered(char *source);

void task7_printWordsOfStringReverse(char *source);

int task8_getCountOfWordsPalindromes(char *source);

char *task9_getStringWithAlternatingWords(char *ch1, char *ch2);

void task4_replaceDigitsWithSpaces(char *s);

#endif
