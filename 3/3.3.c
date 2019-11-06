#include <stdio.h>
#define MAXLINE 1000

void expand (char s1[], char s2[]);

int main() {
    char s[MAXLINE] = "a-z6-9";
    char result[MAXLINE];
    expand(result, s);
    printf("original: %s\n", s);
    printf("expanded: %s\n", result);
}

void expand (char s1[], char s2[]) {
    int i, j, c, d;
    for (i = 0, j = 0; (d = s2[i+2]) != '\0' && ((c = s2[i]) != '\0'); ++i) {
        if (
            s2[i+1] == '-' &&
            (('a' <= c && c <= 'z' && c <= d && d <= 'z') || // check lowercase letters
            ('A' <= c && c <= 'Z' && c <= d && d <= 'Z') || // check uppercase letters
            ('0' <= c && c <= '9' && c <= d && d <= '9'))    // check numbers
        ) {
            // add all elements from c to d to s1
            for (; c <= d; ++c) {
                s1[j++] = c;
            }
            i += 2;
        }
        else {
            s1[j++] = c;
        }
        s1[j] = '\0';
    }
}