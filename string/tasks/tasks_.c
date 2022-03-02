#include "tasks_.h"

bool getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

bool getWordReverse(char *rbegin, char *rend, wordDescriptor *word){
    word->begin = findNonSpaceReverse(rbegin, rend);
    if (*word->begin == *rend)
        return 0;

    word->end = findSpaceReverse(word->begin, rend);

    return 1;
}

void digitToStart(wordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartInWordsOfString(char *s) {
    char *beginSearch = s;
    wordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

char *getEndOfString(char *s) {
    return &s[strlen_(s) - 1];
}

void task1_removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void task2_removeExtraSpaces(char *s) {
    char *begin = ++s;
    while (*begin != '\0') {
        if (isspace(*begin) && isspace(*(s - 1))) {
            begin++;
            continue;
        }

        *(s++) = *begin;
        begin++;
    }
}

void task4_replaceDigitsWithSpaces(char *s) {
    memcpy(_stringBuffer, s, strlen_(s));

    while (*_stringBuffer != '\0') {
        if (isdigit(*_stringBuffer)) {
            int digit = *_stringBuffer % '0';
            memcpy(s, _stringSpaces, digit);
            s += --digit;

            continue;
        }

        *(s++) = *_stringBuffer;
    }

    *s = '\0';
}



