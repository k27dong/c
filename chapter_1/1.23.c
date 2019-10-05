// uncomment

#include <stdio.h>
#define MAXLINE 1000

int get_line (char line[], int limit);
void uncomment (char from[], char to[], int in_comment);

int commenting = 0;

int main() {
    char current_line[MAXLINE];
    char uncommented_line[MAXLINE];

    while ((get_line(current_line, MAXLINE)) != 0) {
        uncomment(current_line, uncommented_line, commenting);
        printf("%s", uncommented_line);
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

void uncomment (char from[], char to[], int in_comment) {
    int i, j, c, copy_line;

    i = j = copy_line = 0;
    while ((c = from[i]) != '\0') {
        // <-- this stops the programming from recording
        /* <-- this stops recording entil it finds this --> */

        if (c == '/') {
            if (!in_comment && from[i+1] == '*') {
                in_comment = 1;
            }         
            if (!in_comment && from[i+1] == '/') {
                copy_line = 1;
                break;  // copy the rest of the content in this line
            }
        }
        if (c == '*') {
            if (in_comment && from[i+1] == '/') {
                in_comment = 0;
            }
        }
        ++i;

        if (!in_comment) {
            to[j] = c;
            ++j;
        }
    }

    if (copy_line) {
        while ((c = from[i]) != '\0') {
            to[j] = c;
            ++j;
        }
    }
}