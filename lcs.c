// C99
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

unsigned lcs_len(const char *const s, const char *const t) {
    unsigned row0[strlen(t)], row1[strlen(t)];
    unsigned *lastrow = row0, *currow = row1;

    memset(lastrow, 0, sizeof(int[strlen(t)]));

    for (unsigned i = 0; i < strlen(s); i++) {
        currow[0] = (t[0] == s[i]) ? 1 : lastrow[0];

        for (unsigned j = 1; j < strlen(t); j++) {
            if (t[j] == s[i]) {
                currow[j] = lastrow[j - 1] + 1;
            } else {
                currow[j] = max(currow[j - 1], lastrow[j]);
            }
        }

        unsigned *temp = lastrow;
        lastrow = currow;
        currow = temp;
    }

    return lastrow[strlen(t)-1];
}

long fsize(FILE *file) {
    long oldpos = ftell(file);
    fseek(file, 0, SEEK_END);
    long size = ftell(file);

    fseek(file, oldpos, SEEK_SET);
    return size;
}

char *read_file(const char *filename) {
    FILE *f;
    
    if ((f = fopen(filename, "rb")) == NULL) {
        return NULL;
    }

    size_t len = fsize(f);
    char *s = (char*) malloc(sizeof(char[len]));
    fread(s, sizeof(char), len, f);
    fclose(f);

    return s;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return -1;
    }

    char *s = read_file(argv[1]);
    char *t = read_file(argv[2]);
    
    if (s == NULL || t == NULL) {
        printf("Could not open.\n");
        return -2;
    }

    unsigned rv = lcs_len(s, t);
    printf("LCS: %d\n", rv);

    free(s);
    free(t);
    return 0;
}
