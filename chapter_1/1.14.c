#include <stdio.h>

int main() {
    int c, i, j;
    int digit[10];

    for (i = 0; i < 10; i++) {
        digit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++digit[c-'0'];
        }
        else {
            // do nothing
        }
    }

    // print graph
    for (i = 0; i < 10; i++) {
        printf("%d: ", i);
        for (j = 0; j < digit[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("END");
}