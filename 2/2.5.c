#include <stdio.h>
#define MAXLINE 1000

int any (char s1[], char s2[]);

int main() {
    char s1[MAXLINE] = "abcdefghijklmn";
    char s2[MAXLINE] = {'f', 'b', '\0'};
    int index;

    index = any(s1, s2);

    printf("The first time s2 exist in s1: %d", index);
}

int any (char s1[], char s2[]) {
    int s1_index, s2_index, s1_holder, s2_holder;

    s1_index = 0;

    while ((s1_holder = s1[s1_index++]) != '\0') {
        s2_index = 0;
        while ((s2_holder = s2[s2_index++]) != '\0') {
            if (s2_holder == s1_holder) {
                return s1_index;
            }
        }
    }

    return -1;
}