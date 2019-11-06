#include <stdio.h>

int main() {
    int i, c, lim;
    char s[10];

    // for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    //     s[i] = c
    // }

    for (i = 0; 1; ++i) {
        if (i < lim - 1) {
            if ((c = getchar()) != '\n') {
                if (c != EOF) {
                    s[i] = c;
                }
            }
        }
    }
}