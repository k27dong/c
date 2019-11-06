#include <stdio.h>

int main() {
    int c, count;

    count = 0;

    // first get to the first word
    c = getchar();
    while (c != EOF && c == ' ') {
        c = getchar();
    }

    // all spaces, terminate
    if (c == EOF) {
        printf("\n%d\n", c);
        return 0;
    }

    ++count;
    while (c != EOF) {
        // find the next space then find the next char,
        while (c != EOF && c != ' ') {
            c = getchar();
        }
        while (c != EOF && c == ' ') {
            c = getchar();
        }
        if (c != EOF) {
            ++count;
        }
    }

    printf("\n%d\n", count);
}