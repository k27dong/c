#include <stdio.h>
#define MAXLINE 1000

int get_line (char line[], int maxline);
void print_line (char line[]);

int main() {
    int current_length;

    char line[MAXLINE]; // to store the current line

    while ((current_length = get_line(line, MAXLINE))) {
        if (current_length >= 80) {
            print_line(line);
        }
    }

    printf("end");
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

void print_line(char s[]) {
    int i, c;

    i = 0;
    while ((c = s[i]) != '\0') {
        putchar(c);
        ++i;
    }
    printf("\n");
}