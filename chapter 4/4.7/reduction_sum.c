#include <stdio.h>
#include <mpi/mpi.h>

int main(int argc, char *argv[]) {
    int id;
    int val;
    int sum_of_vals;
    int p;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    val = id + 1;

    MPI_Reduce(&val, &sum_of_vals, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Finalize();

    if (id == 0) {
        printf("the result of the sum is %d, ", sum_of_vals);
        int r = (p * (p + 1)) / 2;
        if (r == sum_of_vals) {
            printf("which is the correct answer.\n");
            return 0;
        }
        printf("which is NOT correct.\n");

    }

    return 0;
}

