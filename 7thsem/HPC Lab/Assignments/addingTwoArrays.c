#include <stdio.h>
#include <omp.h>
#include <time.h>

void main()
{
	double time_spent = 0.0;
	clock_t begin = clock();
	
    printf("Adding Two Arrays\n");
    int a1[] = {1, 2, 3, 4, 5,6,7,8};
    int a2[] = {11, 12, 13, 14, 15,16,17,18};
    int a3[8];
	omp_set_num_threads(5);
	int i;
	#pragma omp parallel for shared(a1,a2,a3) private(i) 
    for (i = 0; i < 8; i++)
    {
        a3[i] = a1[i] + a2[i];
        #pragma omp critical
        printf("Thread Number:%d = %d\n",omp_get_thread_num(), a3[i]);
    }
    
    clock_t end = clock();
   
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("Runtime is %f seconds", time_spent);
}
