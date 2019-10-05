#include <stdio.h>

int main() {
    int c;
    int flag = 0; // boolean

    c = getchar();
    if (c == EOF) {
        return 0;
    }

    // go to the first word
    while (c == ' ') {
        c = getchar();
    }

    while (c != EOF) {
        if (c != ' ') {
            flag = 1;
            putchar(c);
        }
        else {
            if (flag == 1) {
                printf("\n");
                flag = 0;
            }
            else {
                flag = 0;
            }
        }
        c = getchar();
    }

}