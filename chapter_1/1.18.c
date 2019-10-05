#include <stdio.h>
#define MAXLINE 1000

int get_line (char line[], int maxline);
void print_line (char line[]);
int empty (char line[]);
char trim_line (char line[], int length, char to[]);

int main() {
    char line[MAXLINE];
    int current_length;

    while ((current_length = (get_line(line, MAXLINE))) == 1) {
        if (!empty(line)) {
            // trim
            
            
        }
        print_line(line);
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

void print_line(char s[]) {
    int i, c;

    i = 0;
    while ((c = s[i]) != '\0') {
        printf("%d", c);
        ++i;
    }
    printf("\n");
}

int empty (char s[]) {
    int i, c, is_empty;

    i = 0;
    is_empty = 1;

    // if any letter is not space, is_empty = false, terminate the loop
    while ((c = s[i]) != '\0' && is_empty) {
        if (c != ' ') {
            is_empty = 0;
        }
        ++i;
    }

    return is_empty;
}