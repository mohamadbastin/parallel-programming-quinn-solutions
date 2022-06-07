#include "stdio.h"

int isPrime(int n) {
    if (n == 2 || n == 3)
        return 1;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }

    return 1;
}

int main() {
    int max = 0;
    int last = 2;

    for (int i = 1; i <= 1000000; i += 2) {
        if (isPrime(i)) {
            if (i - last > max) {
//                printf("%d  ,%d\n", last, i);
                max = i - last;
            }
            last = i;
        }
    }

    printf("largest gap between two consecutive  prime numbers is: %d\n", max);

    return 0;
}