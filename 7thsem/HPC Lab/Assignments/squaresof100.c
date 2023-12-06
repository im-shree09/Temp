#include<omp.h>
#include<stdio.h>
#include <time.h>

static int sum =0;
int main(int argc, char* argv)
{
	double start,end;
	start=omp_get_wtime();
	
    #pragma omp parallel
    {
        for(int i=1; i<=100;i++)
        {
            if(i%4==omp_get_thread_num())
            {
                printf("thread No. %d Number : %d Square : %d\n", omp_get_thread_num(), i, i * i);  
                sum+=i*i;
            }
        }
        
    }
    printf("Sum is %d \n",sum);
    end=omp_get_wtime();

    printf("\nTime For Parallel Execution= %f",(end-start));
}
