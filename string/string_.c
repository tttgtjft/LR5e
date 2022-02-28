#include "string_.h"

size_t strlen_(const char *begin){
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char find(char *begin, const char *end, const int ch){
    while (begin != end && *begin != '\0')
        begin++;

    return *begin;
}