#include <stdio.h>
#include "string/string_.h"

int main() {
    char *a = "zxcv";

    printf("%d ", a++);
    printf("%d", a);

    return 0;
}
