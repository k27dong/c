#include <stdio.h>
#define MAXLINE 1000

void squeeze (char s1[], char s2[]);

int main() {

    char s1[MAXLINE] = "abcdefghik";
    char s2[MAXLINE] = {'a', 'd', '\0'};
    // delete all content in s2 from s1
    squeeze(s1, s2);

    printf("%s", s1);
}

void squeeze (char s1[], char s2[]) {
    int s1_index, s2_index, s1_holder, s2_holder, new_string_index;
    
    s1_index = new_string_index = 0;

    while ((s1_holder = s1[s1_index++]) != '\0') {
        s2_index = 0;
        int exist = 0;
        while ((s2_holder = s2[s2_index++]) != '\0') {
            if (s2_holder == s1_holder) {
                exist = 1;
            }
        }

        if (exist == 0) {
            s1[new_string_index++] = s1_holder;
        }
    }
    s1[new_string_index] = '\0';
}