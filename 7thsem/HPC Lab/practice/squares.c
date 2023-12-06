#include<stdio.h>
#include<time.h>
#include<omp.h>

int main(int argc, char * argv){
    double start, end;
    start = omp_get_wtime();
    int sum=0;
    #pragma omp parallel reduction(+,sum) num_threads(100)
    {
        int i = omp_get_thread_num();
        sum = i * i;
    }

    end = omp_get_wtime();
    printf("Total time taken by the program is %f", (end-start));
}