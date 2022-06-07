#include "stdio.h"
#include "mpi/mpi.h"

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

int main(int argc, char *argv[]) {

    int id;
    int p;
    int n = 1000000;
    int max = 0;
    int global_max;
    int isPrime(int);
    int i;
    int limit;
    int last;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    i = (n / p) * id;
    if (i % 2 == 0) i = i + 1;
    limit = (n / p) * (id + 1);

    max = 0;

    // find last

    if (i == 1) {
        last = 2;
    }
    else {
        int flag = 1;
        int ls = i - 2;
        while (flag) {
            if (isPrime(ls)) {
                last = ls;
                max = i - ls;
                flag = 0;
            } else {
                ls -= 2;
            }
//
        }
    }


//    printf("my i is %d\n", i);
//    printf("my last is %d\n", last);
    // normal check
    for (i; i < limit; i += 2) {
        if (isPrime(i)) {
            if (i - last > max) {
                max = i - last;
            }
            last = i;
        }
    }

//    printf("my max is %d\n", max);

    MPI_Reduce(&max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Finalize();

    if (id == 0) {
        printf("largest gap between two consecutive prime numbers is: %d, ", global_max);
        if (global_max == 114) {
            printf("which is correct.\n");
            return 0;
        }
        printf("which is NOT correct.\n");

    }

    return 0;

}