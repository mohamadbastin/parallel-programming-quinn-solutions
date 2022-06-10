#include "stdio.h"
#include "mpi/mpi.h"

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

int main(int argc, char *argv[]) {
    int solutions;
    int global_solutions;
    int id;
    int p;
    int i;
    int start = 100000;
    int end = 999999;
    int limit;
    double elapsed_time;
    double max_elapsed_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    elapsed_time = -MPI_Wtime();

    // get the partitioning right
    i = ((end - start + 1) / p) * id;
    i = i + start;
    if (i != start)i++;
    limit = (((end - start + 1) / p) * (id + 1)) + start;
    if (limit == end + 1) limit = end;

//    printf("start is %d, and end is %d\n", i, limit);

    solutions = 0;
    for (i; i <= limit; i++) {
        if (!isCons(i) && !isSum(i)) {
            solutions++;
        }
    }

    elapsed_time += MPI_Wtime();

    MPI_Reduce(&solutions, &global_solutions, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&elapsed_time, &max_elapsed_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Finalize();

    if (id == 0) {
        printf("Total time is: %f ms\n", elapsed_time*1000);
        printf("the total number of solutions are %d, ", global_solutions);

        if (global_solutions == 527787) {
            printf("which is right.\n");
            return 0;

        }
        printf("which is NOT correct\n.");
    }
    return 0;
}