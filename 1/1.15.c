#include <stdio.h>

float f_to_c (float f);

int main() {
    float f = 48.1;
    float c = f_to_c(f);

    printf("%6.2f", c);
}

float f_to_c (float f) {
    float c;

    c = (f - 32) * 5 / 9;

    return c;
}