#include <stdio.h>

unsigned setbits (unsigned x, int p, int n, unsigned y);

int main() {
    printf("%u", setbits(42918, 5, 3, 2485));
}

unsigned setbits (unsigned x, int p, int n, unsigned y) {
    // xxx000xxx | 000yyy000 -> xxxyyyxxx

}