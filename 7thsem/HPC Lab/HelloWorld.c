#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main(){
    printf("Hello World\n");
#pragma omp parallel
    {
        printf("Hello From thread Number %d\n", omp_get_thread_num());
    }
}