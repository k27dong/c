#include <stdio.h>

int main() {
    float f, c;
    float lower, upper, step;

    lower = -20;
    upper = 150;
    step = 10;

    printf("  C      F\n");

    c = lower;
    while (c <= upper) {
        f = c * (9.0 / 5.0) + 32.0;
        printf("%4.1f %4.2f\n", c, f);
        c = c + step;
    }
}