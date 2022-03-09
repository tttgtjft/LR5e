#include <assert.h>
#include "../tasks/tasks_.h"
#include "../string_.h"
#include "../tasks/tasks_.c"

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
    char s[MAX_STRING_SIZE] = "kurapika";

    task3_reverseLettersOfWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "akiparuk";

    assert(strcmp_(s, expectation) == 0);
}

void test_task3_reverseLettersOfWordsOfString_fewWords() {
    char s[MAX_STRING_SIZE] = "kurapika BEST BOY";

    task3_reverseLettersOfWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "akiparuk TSEB YOB";

    assert(strcmp_(s, expectation) == 0);
}

void test_task3_reverseLettersOfWordsOfString() {
    test_task3_reverseLettersOfWordsOfString_emptyString();
    test_task3_reverseLettersOfWordsOfString_oneWord();
    test_task3_reverseLettersOfWordsOfString_fewWords();
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

void test_task6_areWordsOfStringLexicographicallyOrdered_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(task6_areWordsOfStringLexicographicallyOrdered(s) == true);
}

void test_task6_areWordsOfStringLexicographicallyOrdered_twoWordsEquals() {
    char s[MAX_STRING_SIZE] = "kurapika kurapika";

    assert(task6_areWordsOfStringLexicographicallyOrdered(s) == true);
}

void test_task6_areWordsOfStringLexicographicallyOrdered_w1LessW2() {
    char s[MAX_STRING_SIZE] = "kurapik kurapika";

    assert(task6_areWordsOfStringLexicographicallyOrdered(s) == true);
}

void test_task6_areWordsOfStringLexicographicallyOrdered_w1MoreW2() {
    char s[MAX_STRING_SIZE] = "kurapika kurapik";

    assert(task6_areWordsOfStringLexicographicallyOrdered(s) == false);
}

void test_task6_areWordsOfStringLexicographicallyOrdered() {
    test_task6_areWordsOfStringLexicographicallyOrdered_emptyString();
    test_task6_areWordsOfStringLexicographicallyOrdered_twoWordsEquals();
    test_task6_areWordsOfStringLexicographicallyOrdered_w1LessW2();
    test_task6_areWordsOfStringLexicographicallyOrdered_w1MoreW2();
}

/*void test_task7_printWordsOfStringReverse() {
    char s[MAX_STRING_SIZE] = "kurapik kurapika kur"; //it`s ok

    task7_printWordsOfStringReverse(s);
}*/

void test_task8_getCountOfWordsPalindromes_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(task8_getCountOfWordsPalindromes(s) == 0);
}

void test_task8_getCountOfWordsPalindromes_nonPalindrome() {
    char s[MAX_STRING_SIZE] = "kurapik,BES,BOY";

    assert(task8_getCountOfWordsPalindromes(s) == 0);
}

void test_task8_getCountOfWordsPalindromes_onePalindrome() {
    char s[MAX_STRING_SIZE] = "kurapik BESTSEB BOY";

    assert(task8_getCountOfWordsPalindromes(s) == 1);
}

void test_task8_getCountOfWordsPalindromes_allPalindrome() {
    char s[MAX_STRING_SIZE] = "kurapikakiparuk BESTSEB BOYOB";

    assert(task8_getCountOfWordsPalindromes(s) == 3);
}

void test_task8_getCountOfWordsPalindromes() {
    test_task8_getCountOfWordsPalindromes_emptyString();
    test_task8_getCountOfWordsPalindromes_nonPalindrome();
    test_task8_getCountOfWordsPalindromes_onePalindrome();
    test_task8_getCountOfWordsPalindromes_allPalindrome();
}


void test_task9_getStringWithAlternatingWords_emptyStrings() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    char *s = task9_getStringWithAlternatingWords(s1, s2);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task9_getStringWithAlternatingWords_stringLengthsEquals() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "zharik";

    char *s = task9_getStringWithAlternatingWords(s1, s2);

    char expectation[MAX_STRING_SIZE] = "kurapika zharik";

    assert(strcmp_(s, expectation) == 0);
}

void test_task9_getStringWithAlternatingWords_length1MoreLength2() {
    char s1[MAX_STRING_SIZE] = "kurapika kuruta";
    char s2[MAX_STRING_SIZE] = "zharik";

    char *s = task9_getStringWithAlternatingWords(s1, s2);

    char expectation[MAX_STRING_SIZE] = "kurapika zharik kuruta";

    assert(strcmp_(s, expectation) == 0);
}

void test_task9_getStringWithAlternatingWords_length1LessLength2() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "zharik kuruta";

    char *s = task9_getStringWithAlternatingWords(s1, s2);

    char expectation[MAX_STRING_SIZE] = "kurapika zharik kuruta";

    assert(strcmp_(s, expectation) == 0);
}

void test_task9_getStringWithAlternatingWords() {
    test_task9_getStringWithAlternatingWords_emptyStrings();
    test_task9_getStringWithAlternatingWords_stringLengthsEquals();
    test_task9_getStringWithAlternatingWords_length1MoreLength2();
    test_task9_getStringWithAlternatingWords_length1LessLength2();
}

void test_task10_reverseWordsOfString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    task10_reverseWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task10_reverseWordsOfString_oneWord() {
    char s[MAX_STRING_SIZE] = "kurapika";

    task10_reverseWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_task10_reverseWordsOfString_twoWord() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta";

    task10_reverseWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "kuruta kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_task10_reverseWordsOfString_fewWord() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta zharik";

    task10_reverseWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "zharik kuruta kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_task10_reverseWordsOfString() {
    test_task10_reverseWordsOfString_emptyString();
    test_task10_reverseWordsOfString_oneWord();
    test_task10_reverseWordsOfString_twoWord();
    test_task10_reverseWordsOfString_fewWord();
}

#define EMPTY_STRING 0
#define NOT_FOUND_A_WORD_WITH_A 1
#define FIRST_WORD_WITH_A 2
#define WORD_FOUND 3

int task11_getWordBeforeFirstWordWithA(char *s) {
    char *beginSearch = s;
    wordDescriptor word;

    if (!getWord(beginSearch, &word))
        return EMPTY_STRING;
    else if (isWordWithA(word)) {
        return FIRST_WORD_WITH_A;
    }
    beginSearch = word.end;

    while (getWord(beginSearch, &word)) {
        if (isWordWithA(word))
            return WORD_FOUND;
        beginSearch = word.end;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void test_task11_getWordBeforeFirstWordWithA_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(task11_getWordBeforeFirstWordWithA(s) == EMPTY_STRING);
}

void test_task11_getWordBeforeFirstWordWithA_noWordWithA() {
    char s[MAX_STRING_SIZE] = "kurpik kurut best boy";

    assert(task11_getWordBeforeFirstWordWithA(s) == NOT_FOUND_A_WORD_WITH_A);
}

void test_task11_getWordBeforeFirstWordWithA_firstWordWithA() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    assert(task11_getWordBeforeFirstWordWithA(s) == FIRST_WORD_WITH_A);
}

void test_task11_getWordBeforeFirstWordWithA_wordWithA() {
    char s[MAX_STRING_SIZE] = "kurpik kuruta best boy";

    assert(task11_getWordBeforeFirstWordWithA(s) == WORD_FOUND);
}

void test_task11_getWordBeforeFirstWordWithA() {
    test_task11_getWordBeforeFirstWordWithA_emptyString();
    test_task11_getWordBeforeFirstWordWithA_noWordWithA();
    test_task11_getWordBeforeFirstWordWithA_firstWordWithA();
    test_task11_getWordBeforeFirstWordWithA_wordWithA();
}

void wordDescriptorToString(wordDescriptor word, char *destination) {
    for (; word.begin < word.end; word.begin++)
        *(destination++) = *word.begin;

    *destination = '\0';
}

void test_task12_getLastWordInFirstStringFromSecondString_emptyString() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    wordDescriptor word = task12_getLastWordInFirstStringFromSecondString(s1, s2);

    assert(word.begin == 0 && word.end == 0);
}

void test_task12_getLastWordInFirstStringFromSecondString_noWords() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "kurapika";

    wordDescriptor word = task12_getLastWordInFirstStringFromSecondString(s1, s2);

    assert(word.begin == 0 && word.end == 0);
}

void test_task12_getLastWordInFirstStringFromSecondString_oneWordsMatches() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    wordDescriptor word = task12_getLastWordInFirstStringFromSecondString(s1, s2);

    char s[MAX_STRING_SIZE];

    wordDescriptorToString(word, s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp_(s, expectation) == 0);
}

void test_task12_getLastWordInFirstStringFromSecondString_fewWordsMatches() {
    char s1[MAX_STRING_SIZE] = "kurapika kuruta best boy";
    char s2[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    wordDescriptor word = task12_getLastWordInFirstStringFromSecondString(s1, s2);

    char s[MAX_STRING_SIZE];

    wordDescriptorToString(word, s);

    char expectation[MAX_STRING_SIZE] = "boy";

    assert(strcmp_(s, expectation) == 0);
}

void test_task12_getLastWordInFirstStringFromSecondString() {
    test_task12_getLastWordInFirstStringFromSecondString_emptyString();
    test_task12_getLastWordInFirstStringFromSecondString_noWords();
    test_task12_getLastWordInFirstStringFromSecondString_oneWordsMatches();
    test_task12_getLastWordInFirstStringFromSecondString_fewWordsMatches();
}


void test_task13_isEqualWordsInString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    bool isEqualWords = task13_isEqualWordsInString(s);

    assert(isEqualWords == 0);
}

void test_task13_isEqualWordsInString_noEqualWords() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    bool isEqualWords = task13_isEqualWordsInString(s);

    assert(isEqualWords == 0);
}

void test_task13_isEqualWordsInString_equalWords() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta best boy kuruta";

    bool isEqualWords = task13_isEqualWordsInString(s);

    assert(isEqualWords == 1);
}

void test_task13_isEqualWordsInString() {
    test_task13_isEqualWordsInString_emptyString();
    test_task13_isEqualWordsInString_noEqualWords();
    test_task13_isEqualWordsInString_equalWords();
}


void test_task14_isLettersOfWordsInStringEqual_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(task14_isLettersOfWordsInStringEqual(s) == 0);
}

void test_task14_isLettersOfWordsInStringEqual_noLettersOfWordsEqual() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    assert(task14_isLettersOfWordsInStringEqual(s) == 0);
}

void test_task14_isLettersOfWordsInStringEqual_letterOfWordsEqual() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta kuparika";

    assert(task14_isLettersOfWordsInStringEqual(s) == 1);
}

void test_task14_isLettersOfWordsInStringEqual() {
    test_task14_isLettersOfWordsInStringEqual_emptyString();
    test_task14_isLettersOfWordsInStringEqual_noLettersOfWordsEqual();
    test_task14_isLettersOfWordsInStringEqual_letterOfWordsEqual();
}


void test_task15_getStringFromWordsWhichDifferentFromLastWord_emptyString() {
    char s1[MAX_STRING_SIZE] = "";

    char *s = task15_getStringFromWordsWhichDifferentFromLastWord(s1);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task15_getStringFromWordsWhichDifferentFromLastWord_lastWordOnce() {
    char s1[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    char *s = task15_getStringFromWordsWhichDifferentFromLastWord(s1);

    char expectation[MAX_STRING_SIZE] = "kurapika kuruta best";

    assert(strcmp_(s, expectation) == 0);
}

void test_task15_getStringFromWordsWhichDifferentFromLastWord_lastWordTwice() {
    char s1[MAX_STRING_SIZE] = "kurapika boy kuruta best boy";

    char *s = task15_getStringFromWordsWhichDifferentFromLastWord(s1);

    char expectation[MAX_STRING_SIZE] = "kurapika kuruta best";

    assert(strcmp_(s, expectation) == 0);
}

void test_task15_getStringFromWordsWhichDifferentFromLastWord_allWordsSame() {
    char s1[MAX_STRING_SIZE] = "kurapika kurapika kurapika";

    char *s = task15_getStringFromWordsWhichDifferentFromLastWord(s1);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task15_getStringFromWordsWhichDifferentFromLastWord() {
    test_task15_getStringFromWordsWhichDifferentFromLastWord_emptyString();
    test_task15_getStringFromWordsWhichDifferentFromLastWord_lastWordOnce();
    test_task15_getStringFromWordsWhichDifferentFromLastWord_lastWordTwice();
    test_task15_getStringFromWordsWhichDifferentFromLastWord_allWordsSame();
}



void test_task17_deleteWordsPalindromesFromString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    task17_deleteWordsPalindromesFromString(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task17_deleteWordsPalindromesFromString_noPalindrome() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta";

    task17_deleteWordsPalindromesFromString(s);

    char expectation[MAX_STRING_SIZE] = "kurapika kuruta";

    assert(strcmp_(s, expectation) == 0);
}

void test_task17_deleteWordsPalindromesFromString_onePalindrome() {
    char s[MAX_STRING_SIZE] = "kurapikakiparuk kuruta";

    task17_deleteWordsPalindromesFromString(s);

    char expectation[MAX_STRING_SIZE] = "kuruta";

    assert(strcmp_(s, expectation) == 0);
}

void test_task17_deleteWordsPalindromesFromString_allPalindrome() {
    char s[MAX_STRING_SIZE] = "kurapikakiparuk kurapikakiparuk kurapikakiparuk kurapikakiparuk";

    task17_deleteWordsPalindromesFromString(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s, expectation) == 0);
}

void test_task17_deleteWordsPalindromesFromString() {
    test_task17_deleteWordsPalindromesFromString_emptyString();
    test_task17_deleteWordsPalindromesFromString_noPalindrome();
    test_task17_deleteWordsPalindromesFromString_onePalindrome();
    test_task17_deleteWordsPalindromesFromString_allPalindrome();
}

void test_task18_addToLowerStringLastWordsOfHigherString_emptyString() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    task18_addToLowerStringLastWordsOfHigherString(s1, s2);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp_(s1, expectation) == 0 && strcmp_(s2, expectation) == 0);
}

void test_task18_addToLowerStringLastWordsOfHigherString_s1EqualsS2() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "kuruta";

    task18_addToLowerStringLastWordsOfHigherString(s1, s2);

    char expectation1[MAX_STRING_SIZE] = "kurapika";
    char expectation2[MAX_STRING_SIZE] = "kuruta";

    assert(strcmp_(s1, expectation1) == 0 && strcmp_(s2, expectation2) == 0);
}

void test_task18_addToLowerStringLastWordsOfHigherString_s1MoreS2() {
    char s1[MAX_STRING_SIZE] = "kurapika kuruta";
    char s2[MAX_STRING_SIZE] = "kurapika";

    task18_addToLowerStringLastWordsOfHigherString(s1, s2);

    char expectation[MAX_STRING_SIZE] = "kurapika kuruta";

    assert(strcmp_(s2, expectation) == 0);
}

void test_task18_addToLowerStringLastWordsOfHigherString_s1LessS2() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "kurapika bestie";

    task18_addToLowerStringLastWordsOfHigherString(s1, s2);

    char expectation[MAX_STRING_SIZE] = "kurapika bestie";

    assert(strcmp_(s1, expectation) == 0);
}

void test_task18_addToLowerStringLastWordsOfHigherString() {
    test_task18_addToLowerStringLastWordsOfHigherString_emptyString();
    test_task18_addToLowerStringLastWordsOfHigherString_s1EqualsS2();
    test_task18_addToLowerStringLastWordsOfHigherString_s1MoreS2();
    test_task18_addToLowerStringLastWordsOfHigherString_s1LessS2();
}

void test_tasks() {
    test_task1_removeNonLetters();
    test_task2_removeExtraSpaces();
    test_task3_reverseLettersOfWordsOfString();
    test_task4_replaceDigitsWithSpaces();
    test_task5_replace();
    test_task6_areWordsOfStringLexicographicallyOrdered();
    test_task8_getCountOfWordsPalindromes();
    test_task9_getStringWithAlternatingWords();
    test_task10_reverseWordsOfString();
    test_task11_getWordBeforeFirstWordWithA();
    test_task12_getLastWordInFirstStringFromSecondString();
    test_task13_isEqualWordsInString();
    test_task14_isLettersOfWordsInStringEqual();
    test_task15_getStringFromWordsWhichDifferentFromLastWord();
    test_task17_deleteWordsPalindromesFromString();
    test_task18_addToLowerStringLastWordsOfHigherString();
}