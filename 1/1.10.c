#include <stdio.h>

int main() {
    int c;

    while((c = getchar()) != EOF) {
        if (c == '\\') {
            c = getchar();
            if (c == 't') {
                putchar('\t');
            }
            else if (c == 'b') {
                putchar('\b');
            }
            else if (c == '\\') {
                putchar('\\');
            }
            else {
                // do nothing
            }
        }
        else {
            putchar(c);
        }
    }
}