//
// Created by mohamad on 6/10/22.
//

#include "stdio.h"
#include <time.h>

int isCons(int i) {
    char str[6];
    sprintf(str, "%d", i);

    for (int j = 0; j < 5; j++) {
        if (str[j] == str[j + 1]) {
            return 1;
        }
    }
    return 0;
}

int isSum(int num) {
    int rem, sum = 0;

    while (num != 0) {
        rem = num % 10;
        num = num / 10;
        sum = sum + rem;
    }

    if (sum == 7 || sum == 11 || sum == 13) {
        return 1;
    }
    return 0;
}

int main() {
    clock_t begin = clock();

    int solutions = 0;
    for (int i = 100000; i <= 999999; i++) {
        if (!isCons(i) && !isSum(i)) {
            solutions++;
        }
    }

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("total number of solutions are: %d\n", solutions);
    printf("time spent: %f\n", time_spent*1000);
    return 0;

}