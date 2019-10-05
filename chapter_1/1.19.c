#include <stdio.h>
#define MAXLINE 1000

int get_line (char s[], int length);
void print_line_reverse (char s[], int length);

int main() {
    char line[MAXLINE];
    int current_length;

    while ((current_length = get_line(line, MAXLINE))) {
        print_line_reverse(line, current_length);
    }    
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

void print_line_reverse (char s[], int length) {
    int i;
    char c;

    for (i = length - 2; i >= 0; --i) {
        c = s[i];
        printf("%c", c);
    }
    printf("\n");
}