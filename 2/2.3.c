#include <stdio.h>

#define MAXLINE 1000

int get_line (char line[], int limit);
unsigned long htoi (char s[]);

int main() {
    int length;
    char line[MAXLINE];

    while ((length = get_line(line, MAXLINE)) > 0) {
        printf("%lu\n", htoi(line));
    }
}

unsigned long htoi (char s[]) {
    int i, c;
    unsigned long n;

    n = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        for (i = 2; s[i] != '\0'; ++i) {
            c = s[i];
            n *= 16;

            if (c >= '0' && c <= '9') {
                n += c - '0';   // if it's a number
            }
            else if (c >= 'a' && c <= 'f') {
                n += c - 'a';   // if it's a lowercase letter
            }
            else if (c >= 'A' && c <= 'F') {
                n += c - 'A';   // if it's a uppercase letter
            }
        }
    }

    return n;
}

int get_line (char s[], int lim) {
    int c, i;

    for  (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}