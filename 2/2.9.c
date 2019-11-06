/**
 * x &= (x - 1) is equal to x = x & (x - 1)
 * 
 * for binary numbers, x - 1 would always invert the rightmost digit,
 * if the rightmost digit is 1, it is set to 0. 
 * if not, then all 0-bit digit would be set to 0, until a 1-bit is found
 * AND the two numbers would make all borrowed digit 0, hence this operation
 * will always remove the rightmost 1-bit digit of any number.
 */

int bitcount (unsigned x);

int bitcount (unsigned x) {
    int b;
    for (b = 0; x != 0; x &= (x - 1)) {
        ++b;
    }
    return b;
}