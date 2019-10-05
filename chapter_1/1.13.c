#include <stdio.h>

int main() {
    int c, i, count, j;
    int length[12];

    for (i = 0; i < 12; ++i) {
        length[i] = 0;
    }

    c = getchar();
    if (c == EOF) {
        return 0;
    }

    while (c == ' ') {
        c = getchar();
    }

    // first word
    while (c != EOF) {
        count = 0;
        while (!(c >= '0' && c <= 9) && c != ' ' && c != '\n' && c != '\t' && c != EOF) {
            ++count;
            c = getchar();
        }

        if (count <= 13) {
            ++length[count-1];
        }

        c = getchar();
    }

    // print array
    for (i = 0; i < 12; ++i) {
        printf("%d: ", i);
        for (j = 0; j < length[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}
