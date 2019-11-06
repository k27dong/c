#include <stdio.h>

int main() {
    long c = 0; // initial count
    int g;

    while ((g = getchar()) != EOF) {
        if (g == ' ' || g == '\n' || g == '\t') {
            ++c;
        }
    }

    printf("%ld", c);
}