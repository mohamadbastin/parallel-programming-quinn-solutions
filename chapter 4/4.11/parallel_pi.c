#include "stdio.h"
#include "mpi/mpi.h"

int main(int argc, char *argv[]) {
    int intervals = 1000000;
    int end = intervals;
    double area;
    double global_area;
    double ysum;
    double xi;
    int i;
    int limit;
    int p;
    int id;
    double elapsed_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    elapsed_time = -MPI_Wtime();
    // get the partitioning right
    i = (end / p) * id;
    limit = (end / p) * (id + 1);

//    printf("%d start is %d and end is %d\n", id, i, limit);
    for (i; i < limit; i++) {
        xi = (1.0 / intervals) * (i + 0.5);
        ysum += 4.0 / (1.0 + xi * xi);
    }

    area = ysum * (1.0 / intervals);

    MPI_Reduce(&area, &global_area, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    elapsed_time += MPI_Wtime();
    MPI_Finalize();

    if (id == 0) {
        printf("the result of integral is: %13.11f\n", global_area);
        printf("Total time is: %f ms\n", elapsed_time * 1000);
    }
    return 0;
}