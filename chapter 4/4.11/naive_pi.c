#include "stdio.h"
#include "time.h"

int main() {
    int intervals = 1000000;
    double area;
    double ysum;
    double xi;
    int i;
    clock_t begin = clock();
    ysum = 0.0;
    for (i = 0; i < intervals; i++) {
        xi = (1.0 / intervals) * (i + 0.5);
//        printf("%f\n", xi);
        ysum += 4.0 / (1.0 + xi * xi);
    }

    area = ysum * (1.0 / intervals);
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("Area is %13.11f\n", area);
    printf("time spent: %f ms\n", time_spent * 1000);
    return 0;

}
