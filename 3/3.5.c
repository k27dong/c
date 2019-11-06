void itob (int n, char s[], int b) {
    int i, sign;
    i = 0, sign = n;

    do {
        s[i++] = abs(n % b) + '0';
    } while ((n /= b) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';

    reverse(s)
}

void abs (int n) {
    return n < 0 ? -n : n;
}