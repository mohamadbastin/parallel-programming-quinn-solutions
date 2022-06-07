#include <stdio.h>
#include <mpi/mpi.h>
#include "time.h"

#define EXTRACT_BIT(n, i) ( (n& (1<<i) ) ?1: 0)

int main(int argc, char *argv[]) {
//    printf("initializing\n");
    int solution;
    int global_solution;
    int i;
    int id;
    int p;
    int check_circuit(int, int);
    double elapsed_time;

    MPI_Init(&argc, &argv);
    MPI_Barrier(MPI_COMM_WORLD);
    elapsed_time = -MPI_Wtime();
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    solution = 0;

    for (i = id; i < 65536; i += p) {
        solution += check_circuit(id, i);
    }

    MPI_Reduce(&solution, &global_solution, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    elapsed_time += MPI_Wtime();
    printf("Process %d is done\n", id);
    fflush(stdout);

    MPI_Finalize();

    if (id == 0) printf("Total number of solutions is: %d\n", global_solution);
    printf("Process %d : Total time is: %f\n", id, elapsed_time);
    return 0;
}


//void check_circuit(int id, int i) {
//    printf("im process %d doing work %d\n", id, i);
//}

int check_circuit(int id, int z) {
    int v[16];
    int i;
    for (i = 0; i < 16; i++) {
        v[i] = EXTRACT_BIT(z, i);
    }

    if ((v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3])
        && (!v[3] || !v[4]) && (v[4] || !v[5])
        && (v[5] || !v[6]) && (v[5] || v[6])
        && (v[6] || !v[15]) && (v[7] || !v[8])
        && (!v[7] || !v[13]) && (v[8] || v[9])
        && (v[8] || !v[9]) && (!v[9] || !v[10])
        && (v[9] || v[11]) && (v[10] || v[11])
        && (v[12] || v[13]) && (v[13] || !v[14])
        && (v[14] || v[15])) {
//        printf(" %d) %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", id,
//               v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9],
//               v[10], v[11], v[12], v[13], v[14], v[15]);
//        fflush(stdout);
        return 1;
    }
    return 0;
}