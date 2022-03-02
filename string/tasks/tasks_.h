#ifndef LR5E_TASKS__H
#define LR5E_TASKS__H

#include "../string_.h"

typedef struct wordDescriptor {
    char *begin;
    char *end;
} wordDescriptor;

void task1_removeNonLetters(char *s);

void task2_removeExtraSpaces(char *s);

void task4_replaceDigitsWithSpaces(char *s);

#endif
