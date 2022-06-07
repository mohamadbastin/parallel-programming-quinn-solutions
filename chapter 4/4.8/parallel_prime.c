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
    int solutions;
    int global_solution;
    int isPrime(int);
    int i;
    int limit;
    int flag = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    i = (n / p) * id;
    if (i % 2 == 0) i = i + 1;
    limit = (n / p) * (id + 1);

    solutions = 0;

    // check for the chain links
    if (i - 2 >= 1) {
        if (isPrime(i - 2) && isPrime(i)) {
            solutions += 1;
        }
    }
    // normal check
    for (i; i < limit; i += 2) {
        if (isPrime(i)) {
            if (flag == 1) {
                solutions++;
            }
            flag = 1;
        } else {
            flag = 0;
        }
    }

    MPI_Reduce(&solutions, &global_solution, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Finalize();

    if (id == 0) {
        printf("total number of solutions is: %d, ", global_solution);
        if (global_solution == 8169) {
            printf("which is correct.\n");
            return 0;
        }
        printf("which is NOT correct.\n");

    }

    return 0;

}