// detab

#include <stdio.h>
#define TAB 4
#define MAXLINE 1000

int get_line (char s[], int length);
void detab (char from[], char to[], int tab_length);

int main() {
    char current_line[MAXLINE];
    char detabbed_line[MAXLINE];

    while (get_line(current_line, MAXLINE) != 0) {
        detab(current_line, detabbed_line, TAB);
        printf("%s\n", detabbed_line);
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

void detab (char from[], char to[], int tab_length) {
    // replace '\t' with spaces
    int i, j, k, c, space;

    i = j = 0;
    while ((c = from[i]) != '\0') {
        if (c == '\t') {
            // calculate the number of space until the next tab
            space = tab_length - j % tab_length;    
            for (k = 0; k < space; ++k) {
                to[j] = ' ';            
                ++j;
            }
            --j;
        }
        else {
            to[j] = c;
        }
        ++i;
        ++j;
    }
}