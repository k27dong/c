#include <stdio.h>
#include <limits.h>

int main() {
    printf("Signed char: %d, %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0, %d\n\n", UCHAR_MAX);

    printf("Signed short: %d, %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short: 0, %d\n\n", USHRT_MAX);

    printf("Signed int: %d, %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int: 0, %d\n\n", UINT_MAX);

    printf("Signed long: %ld, %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: 0, %lu", ULONG_MAX);
}