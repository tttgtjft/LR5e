#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <memory.h>

#ifndef LR5E_STRING__H
#define LR5E_STRING__H

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char *_stringSpaces = "                                        ";
char _stringBuffer[MAX_STRING_SIZE + 1];

size_t strlen_(char *begin);

char *find(char *begin, const char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(char *lhs, char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

#endif
