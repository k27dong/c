#include <stdio.h>

main() {
    int c;

    c = getchar();

    if (c != EOF) {
        printf("1");
    }
    else {
        printf("0");
    }
}