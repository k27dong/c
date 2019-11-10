#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

double atof (char s[]);

main() {
    char s[MAXLINE] = "20.23e-1";
    double answer = atof(s);
    printf("the number is: %f\n", answer);
}

double atof (char s[]) {
    double val, power;
    int i, sign, esign, eval;

    for (i = 0; isspace(s[i]); i++); // skips whitespaces
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') i++;

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    
    if (s[i] == '.') i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'E' || s[i] == 'e') {
        i++;
        esign = (s[i] == '-' ? -1 : 1);
        if (s[i] == '+' || s[i] == '-') i++;

        for (eval = 0; isdigit(s[i]); i++) {
            eval = 10 * eval + (s[i] - '0');
        }

        if (esign < 1) eval++;

        for (; eval > 1; eval--) {
            power = esign > 0 ? power * 10 : power / 10;
        }
    }
    return sign * val / power;
}