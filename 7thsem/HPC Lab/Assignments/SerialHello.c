#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<omp.h>

int main(int argc, char* argv)
{
	double time_spent = 0.0;
 
    clock_t begin = clock();
	printf("Thread: %d\nHello World\n",omp_get_thread_num());
    clock_t end = clock();
 
   
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("Runtime is %f seconds", time_spent);
 

}
