#include <stdio.h>

int main() {
    int c;

    printf("\n");
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            while ((c = getchar()) == ' ') {};
            putchar(' ');
        }
        putchar(c);
    }
}