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
        if (isspace(*begin) && isspace(*(s - 1)))
            begin++;
        else{
            *(s++) = *begin;
            begin++;
        }
    }

    *s = '\0';
}

//------------------TASK3(a)------------------//

bool getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    return true;
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
    if (word->begin <= rend)
        return false;

    word->end = findSpaceReverse(word->begin, rend);

    return true;
}

void reverseLettersOfWords(wordDescriptor word) {
    char *endStringBuffer = copy(word.end + 1, word.begin + 1, _stringBuffer);
    copyReverse(endStringBuffer - 1, _stringBuffer - 1, word.end + 1);
}

void task3_reverseLettersOfWordsOfString(char *s) {
    char *beginSearch = &s[strlen_(s) - 1];
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

bool task6_areWordsOfStringLexicographicallyOrdered(char *source) {
    char *beginSearch = source;
    wordDescriptor word1;
    wordDescriptor word2;

    if (!getWord(beginSearch, &word1))
        return true;
    beginSearch = word1.end;

    while (getWord(beginSearch, &word2)) {
        if (!areWordsLexicographicallyOrdered(word1, word2))
            return false;

        word1 = word2;
        beginSearch = word1.end;
    }

    return true;
}

//------------------TASK7------------------//

void task7_printWordsOfStringReverse(char *source) {
    char *beginSearch = &source[strlen_(source)];
    wordDescriptor word;
    while (getWordReverse(beginSearch, source, &word)) {
        beginSearch = word.end;

        for (; word.end + 1 <= word.begin; word.end++)
            printf("%c", *word.end);

        printf("\n");
    }
}

//------------------TASK8------------------//

bool isWordPalindrome(wordDescriptor word) {
    word.end--;
    for (; word.begin < word.end; word.begin++, word.end--)
        if (*word.begin != *word.end)
            return false;

    return true;
}

int task8_getCountOfWordsPalindromes(char *source) {
    char *beginSearch = source;
    wordDescriptor word;

    int counterWordsPalindrome = 0;
    while (getWord(beginSearch, &word)) {
        if (isWordPalindrome(word))
            counterWordsPalindrome++;

        beginSearch = word.end;
    }

    return counterWordsPalindrome;
}

//------------------TASK9------------------//

char *task9_getStringWithAlternatingWords(char *ch1, char *ch2) {
    memcpy(_stringBuffer, _stringSpaces, MAX_STRING_SIZE);
    char *beginSearch1 = ch1, *beginSearch2 = ch2;
    char *endStr = _stringBuffer - 1;

    wordDescriptor word1, word2;
    bool isW1Found, isW2Found;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            endStr = copy(word1.begin, word1.end, endStr + 1);
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            endStr = copy(word2.begin, word2.end, endStr + 1);
            beginSearch2 = word2.end;
        }
    }

    *(endStr + (endStr == _stringBuffer - 1)) = '\0';

    return _stringBuffer;
}

//------------------TASK10------------------//

void task10_reverseWordsOfString(char *source) {
    size_t sourceLen = strlen_(source);
    copyReverse(source + sourceLen - 1, source - 1, _stringBuffer);
    memcpy(source, _stringBuffer, sourceLen);
    task3_reverseLettersOfWordsOfString(source);
}

//------------------TASK11------------------//

bool isWordWithA(wordDescriptor word) {
    for (; word.begin < word.end; word.begin++)
        if (*word.begin == 'a')
            return true;

    return false;
}

void printWord(wordDescriptor word) {
    for (; word.begin < word.end; word.begin++)
        printf("%c", *word.begin);

    printf("\n");
}

void task11_printWordBeforeFirstWordWithA(char *s) {
    char *beginSearch = s;
    wordDescriptor word;

    if (!getWord(beginSearch, &word))
        printf("there is no such word in this string");
    wordDescriptor previousWord = word;

    bool isAinString = false;
    while (getWord(beginSearch, &word)) {
        if (isWordWithA(word)) {
            printWord(previousWord);
            isAinString = true;
            break;
        }

        previousWord = word;
    }

    if (!isAinString)
        printf("there is no such word in this string");
}

//------------------TASK12------------------//

bool isWordInString(char *source, char *w1Begin, char *w1End) {
    char *beginSearch = source;
    wordDescriptor wordString;

    while (getWord(beginSearch, &wordString)) {
        size_t wordStringSize = wordString.end - wordString.begin;
        size_t wordSize = w1End - w1Begin;
        if (wordStringSize == wordSize && memcmp(w1Begin, wordString.begin, wordSize) == 0)
            return true;

        beginSearch = wordString.end;
    }

    return false;
}

wordDescriptor task12_getLastWordInFirstStringFromSecondString(char *s1, char *s2) {
    char *beginSearch = s1 + strlen_(s1) - 1;
    wordDescriptor word;

    while (getWordReverse(beginSearch, s1 - 1, &word)) {
        if (isWordInString(s2, word.end + 1, word.begin + 1)) {
            char *t = word.begin;
            word.begin = word.end + 1;
            word.end = t + 1;
            return word;
        }

        beginSearch = word.end;
    }

    return (wordDescriptor) {NULL, NULL};
}

//------------------TASK13------------------//

bool task13_isEqualWordsInString(char *source) {
    char *beginSearch = source;
    wordDescriptor word;

    while (getWord(beginSearch, &word)) {
        beginSearch = word.end;

        if (isWordInString(beginSearch, word.begin, word.end))
            return true;
    }

    return false;
}

//------------------TASK14------------------//

int compare_char(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool task14_isLettersOfWordsInStringEqual(char *source) {
    memcpy(_stringBuffer, source, strlen_(source) + 1);

    char *beginSearch = _stringBuffer;
    wordDescriptor word;

    while (getWord(beginSearch, &word)) {
        qsort(word.begin, word.end - word.begin, sizeof(char), compare_char);
        beginSearch = word.end;
    }

    return task13_isEqualWordsInString(_stringBuffer);
}

//------------------TASK15------------------//

char *task15_getStringFromWordsWhichDifferentFromLastWord(char *source) {
    char *beginSearch = source + strlen_(source) - 1;
    wordDescriptor lastWord;

    if (!getWordReverse(beginSearch, source - 1, &lastWord))
        return "\0";
    size_t lastWordSize = lastWord.begin - lastWord.end;

    beginSearch = source;
    wordDescriptor word;

    memcpy(_stringBuffer, _stringSpaces, MAX_STRING_SIZE);
    char *endStringBuffer = _stringBuffer - 1;
    while (getWord(beginSearch, &word)) {
        size_t wordSize = word.end - word.begin;
        if (wordSize != lastWordSize || memcmp(word.begin, lastWord.end + 1, wordSize) != 0)
            endStringBuffer = copy(word.begin, word.end, endStringBuffer + 1);

        beginSearch = word.end;
    }

    *(endStringBuffer + (endStringBuffer == _stringBuffer - 1)) = '\0';

    return _stringBuffer;
}

//------------------TASK16------------------//

wordDescriptor task16_getLastWordInFirstStringFromSecondString(char *s1, char *s2) {
    return task12_getLastWordInFirstStringFromSecondString(s1, s2);
}

//------------------TASK17------------------//

void task17_deleteWordsPalindromesFromString(char *source) {
    memcpy(_stringBuffer, source, strlen_(source));
    char *beginSearch = _stringBuffer;
    wordDescriptor word;

    memcpy(source, _stringSpaces, MAX_STRING_SIZE);
    char *endSource = source - 1;

    while (getWord(beginSearch, &word)) {
        if (!isWordPalindrome(word))
            endSource = copy(word.begin, word.end, endSource + 1);

        beginSearch = word.end;
    }

    *(endSource + (endSource == source - 1)) = '\0';
}

//------------------TASK18------------------//

int getCountOfWordsOfString(char *source) {
    char *beginSearch = source;
    wordDescriptor word;

    int counterWords = 0;
    while (getWord(beginSearch, &word)) {
        counterWords++;

        beginSearch = word.end;
    }

    return counterWords;
}

void addToLowerStringLastWordsOfHigherString_(char *s1, size_t s1Size, size_t s1CountWords, char *s2, size_t s2Size, size_t s2CountWord){
    s1[s1Size] = ' ';
    char *beginSearch = s2 + s2Size;
    wordDescriptor word;

    char *endStr = s1 + s1Size;
    while (getWordReverse(beginSearch, s2 - 1, &word)) {
        endStr = copy(word.end + 1, word.begin + 1, endStr + 1);

        if (--s2CountWord == s1CountWords)
            break;

        beginSearch = word.end;

    }

    *(endStr) = '\0';
}

void task18_addToLowerStringLastWordsOfHigherString(char *s1, char *s2) {
    size_t s1Size = strlen_(s1);
    size_t s2Size = strlen_(s2);

    size_t s1CountWords = getCountOfWordsOfString(s1);
    size_t s2CountWords = getCountOfWordsOfString(s2);

    if (s1CountWords < s2CountWords)
        addToLowerStringLastWordsOfHigherString_(s1, s1Size, s1CountWords, s2, s2Size, s2CountWords);
    else if (s2CountWords < s1CountWords)
        addToLowerStringLastWordsOfHigherString_(s2, s2Size, s2CountWords, s1, s1Size, s1CountWords);
}

//------------------TASK19------------------//


