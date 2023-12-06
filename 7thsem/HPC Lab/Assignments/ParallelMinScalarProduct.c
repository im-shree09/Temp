#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2)
{

	int temp = *num1;
	*num1 =  *num2;
	*num2 = temp;
}

int sort(int arr[],int n) {
    int i,j;
    for (i = 0; i < n-1; i++) {
        #pragma omp parallel for default(none),shared(arr,n,i)
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp;
            }
        }
    }
}

int dec_sort(int arr[],int n) {
    int i,j;
    for( i = 0; i < n; i++ )
	{ 
		#pragma omp parallel for default(none),shared(arr,n,i)
		for (j = i + 1; j < n; ++j)
        {
         printf("Thread:%d\n",omp_get_thread_num());
            if (arr[i] < arr[j])
            {
                int a = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = a;
            }
        }
	}

}


int main (int argc, char *argv[]) {
	int SIZE =5;
	int arr1[5]={2,1,4,6,3};
    int arr2[5]={2,1,5,4,3};
	int n = SIZE;
	int i=0, j=0; 
	int first;
	double start,end;
	start=omp_get_wtime();
	sort(arr1,n);
    dec_sort(arr2,n);
    int sum = 0;
    for(i = 0; i < n ; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }
    printf("\nMinimum scalar product is: ");
    printf("%d",sum);
    end=omp_get_wtime();

    printf("\nTime Parallel= %f",(end-start));
}