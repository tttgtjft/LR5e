#include "tasks_.h"

//------------------TASK1------------------//

char *getEndOfString(char *s) {
    return &s[strlen_(s)];
}

void task1_removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

//------------------TASK2------------------//

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

    *s = '\0';
}

//------------------TASK3(a)------------------//

bool getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

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

//------------------TASK3(b)------------------//

bool getWordReverse(char *rbegin, char *rend, wordDescriptor *word) {
    word->begin = findNonSpaceReverse(rbegin, rend);
    if (word->begin == rend)
        return 0;

    word->end = findSpaceReverse(word->begin, rend);

    return 1;
}

void reverseLettersOfWords(wordDescriptor word) {
    char *endStringBuffer = copyReverse(word.begin, word.end, _stringBuffer);
    char *recPosition = word.end + 1;
    memcpy(recPosition, _stringBuffer, endStringBuffer - _stringBuffer);
}

void task3_reverseLettersOfWordsOfString(char *s) {
    char *beginSearch = &s[strlen_(s)];
    wordDescriptor word;
    while (getWordReverse(beginSearch, s - 1, &word)) {
        reverseLettersOfWords(word);
        beginSearch = word.end;
    }
}

//------------------TASK4------------------//

void task4_replaceDigitsWithSpaces(char *s) {
    memcpy(_stringBuffer, s, strlen_(s) + 1);

    int i = 0;
    while (_stringBuffer[i] != '\0') {
        if (isdigit(_stringBuffer[i])) {
            int digit = _stringBuffer[i++] % '0';
            memcpy(s, _stringSpaces, digit);
            s += digit;

            continue;
        }

        *(s++) = _stringBuffer[i++];
    }

    *s = '\0';
}

//------------------TASK5------------------//

void task5_replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    wordDescriptor word2 = {w2, w2 + w2Size};

    char *beginSearch = source;
    wordDescriptor word;

    if (w1Size >= w2Size)
        while (getWord(beginSearch, &word)) {
            if (strcmp_(w1, word.begin) == 0) {
                char *endDst = copy(word2.begin, word2.end, word.begin);
                memcpy(endDst, _stringSpaces, w1Size - w2Size);
            }

            beginSearch = word.end;
        }
    else {
        size_t sourceLen = strlen_(source);
        memcpy(_stringBuffer, source, sourceLen + 1);

        while (getWord(beginSearch, &word)) {
            beginSearch = word.end;

            if (w1Size == word.end - word.begin && memcmp(w1, word.begin, w1Size) == 0) {
                beginSearch += (w2Size - w1Size);
                memcpy(word.begin, w2, w2Size);
                long long endStringBuffer = word.end - source;
                if (_stringBuffer[endStringBuffer] != '\0')
                    memcpy(beginSearch, &_stringBuffer[endStringBuffer], sourceLen - endStringBuffer);
            }
        }
    }
}

//------------------TASK6------------------//

bool areWordsLexicographicallyOrdered(wordDescriptor w1, wordDescriptor w2) {
    size_t w1Size = w1.end - w1.begin;
    size_t w2Size = w2.end - w2.begin;

    if (w1Size < w2Size) {
        while (w1.begin != w1.end)
            if (*(w1.begin++) != *(w2.begin++))
                return false;
    } else if (w1Size == w2Size) {
        while (w1.begin != w1.end)
            if (*(w1.begin++) > *(w2.begin++))
                return false;
    } else
        return false;

    return true;
}

bool task6_areWordsOfStringLexicographicallyOrdered(char *source){
    char *beginSearch = source;
    wordDescriptor word1;
    wordDescriptor word2;

    if (!getWord(beginSearch, &word1))
        return true;
    beginSearch = word1.end;

    while (getWord(beginSearch, &word2)){
        if (!areWordsLexicographicallyOrdered(word1, word2))
            return false;

        word1 = word2;
        beginSearch = word1.end;
    }

    return true;
}

//------------------TASK7------------------//

void task7_printWordsOfStringReverse(char *source){
    char *beginSearch = &source[strlen_(source)];
    wordDescriptor word;
    while (getWordReverse(beginSearch, source, &word)){
        beginSearch = word.end;

        for (; word.end + 1 <= word.begin; word.end++)
            printf("%c", *word.end);

        printf("\n");
    }
}

//------------------TASK8------------------//

bool isWordPalindrome(wordDescriptor word){
    for (; word.begin < word.end; word.begin++, word.end--)
        if (*word.begin != *word.end)
            return false;

    return true;
}

int task8_getCountOfWordsPalindromes(char *source){
    char *beginSearch = source;
    wordDescriptor word;

    int counterWordsPalindrome = 0;
    while (getWord(beginSearch, &word)){
        if (isWordPalindrome(word))
            counterWordsPalindrome++;

        beginSearch = word.end;
    }

    return counterWordsPalindrome;
}

//------------------TASK9------------------//

char *task9_getStringWithAlternatingWords(char *ch1, char *ch2){
    char *beginSearch1 = ch1, *beginSearch2 = ch2;
    char *endStr = _stringBuffer - 1;
    wordDescriptor word1, word2;
    bool isW1Found, isW2Found;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found){
                if (isW1Found && isW2Found){
                    endStr = copy(word1.begin, word1.end, endStr + 1);
                    endStr = copy(word2.begin, word2.end, endStr + 1);
                }
                else if (isW1Found)
                    endStr = copy(word1.begin, word2.end, endStr + 1);
                else
                    endStr = copy(word2.begin, word2.end, endStr + 1);
    }

    *endStr = '\0';
    return _stringBuffer;
}

//------------------TASK10------------------//

void reverseWordsOfString(char *source){
    copyReverse(&source[strlen_(source) + 1], source - 1, _stringBuffer);

    char *beginSearch = _stringBuffer;
    wordDescriptor word;


}

//------------------TASK1------------------//

//------------------TASK1------------------//


