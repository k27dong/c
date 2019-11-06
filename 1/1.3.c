#include <stdio.h>
#define LOWER 0;
#define UPPER 300;
#define STEp 20;

main() {
    float fahr, celcius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("F and C transition\n");
    while (fahr <= upper) {
        celcius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
}