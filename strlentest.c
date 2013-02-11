#include <stdio.h>
#include <string.h>
#include "rdtsc.h"

typedef unsigned long long ull;

void fn(const char* const str) {
    for (unsigned int i=0; i<strlen(str); i++) {
        printf("%c\n", str[i]);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s string\n", argv[0]);
        return -1;
    }

    fn((const char* const) argv[1]);

    return 0;
}
