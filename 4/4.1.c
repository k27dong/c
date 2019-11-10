#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int strindex (char s[], char t[]);

main() {
    char s[MAXLINE] = "ouf";
    char t[MAXLINE] = "weather is ouf sunny life is goufd";
    int index = strindex(s, t);
    printf("%d\n", index);
}

int strindex (char s[], char t[]) {
    int s_i, t_i, j;
    s_i = strlen(s) - 1;
    t_i = strlen(t) - 1;
    
    for (; t_i >= 0; t_i--) {
        for (j = 0; j < s_i && s[s_i - j] == t[t_i]; ++j, --t_i);
        if (j == s_i) {
            return t_i;
        }
    }
    return -1;
}