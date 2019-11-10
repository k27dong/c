/**
 * our version of `itoa` cannot handle the largest negative number because
 * the largest negative number is -(2^wordsize - 1), but the largest positive
 * number is 2^wordsize
 * ex: in a 4-bit system, the largest negative number is -8, while the 
 * largest positive number is 7
 * 
 * in this case n = -n won't work
 */

void itoa(int n, char s[]);
int abs(int n);

void itoa (int n, char s[]) {
    int i, sign;
    i = 0, sign = n;

    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';

    reverse(s);
}

int abs (int n) {
    return n < 0 ? -n : n;
}