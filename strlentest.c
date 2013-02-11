#include <stdio.h>
#include <string.h>
#include "rdtsc.h"

typedef unsigned long long ull;

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s string\n", argv[0]);
        return -1;
    }

    const char* k = argv[1];

    for (unsigned int i=0; i<strlen(k); i++) {
        printf("%c\n", k[i]);
    }

    return 0;
}
