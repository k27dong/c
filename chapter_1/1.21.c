// entab

#include <stdio.h>
#define TAB 4
#define MAXLINE 1000

int get_line (char line[], int limit);
void entab (char from[], char to[], int tab_length);

int main() {
    char current_line[MAXLINE];
    char entabbed_line[MAXLINE];

    while ((get_line(current_line, MAXLINE)) != 0) {
        entab(current_line, entabbed_line, TAB);
        printf("%s", entabbed_line);
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

void entab (char from[], char to[], int tab_length) {
    int i, j, k, l, c, m, has_content;

    c = from[0];
    i = j = 0;

    /**
     * i: pointer on the original array
     * j: pointer on the result array
     * k: length counter in this tab (will never exceed the tab_length)
     * l: number of space temporarily saved in this tab
     * m: for loop counter
     * c: temporary holder of the current char
     * has_content: boolean, if the current tab has anything left
     **/ 
    
    while (c != '\0') {
        int has_content = 0;
        k = l = 0;
        while (k < tab_length && c != '\0') {
            if (c != ' ') {
                has_content = 1;
                for (m = 0; m < l; ++m, ++j) {
                    to[j] = ' ';
                }
                to[j] = c;
            }
            else {
                ++l;
            }
            ++i, ++k;
            c = from[i];
        }
        if (has_content == 0) {
            if (c != '\0') {
                to[j] = '\t';
                ++j;
            }
            else {
                for (m = 0; m < k; ++m, ++j) {
                    to[j] = ' ';
                }
            }
        }
        c = from[i];
    }
}