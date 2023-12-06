#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(int argc, char* argv)
{
	double start,end;
	start=omp_get_wtime();
 

    	#pragma omp parallel
	{
		printf("Thread: %d\nHello World\n",omp_get_thread_num());
	}
 
    end=omp_get_wtime();

    printf("\nTime For Parallel Execution= %f",(end-start));
 

}
