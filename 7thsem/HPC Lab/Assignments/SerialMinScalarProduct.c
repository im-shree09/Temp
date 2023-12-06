// C Program to find the minimum scalar product of two vectors (dot product) 
#include<stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC

int sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++) {
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

int sort_des(int arr[], int n)
{
    int i,j;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                int a = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = a;
            }
        }
    }
}
int main()
{
    double time_spent = 0.0;
    clock_t begin = clock();

    //fill the code; 
    int n=5;
    // printf("\nEnter number of elements: ");
    // scanf("%d",&n);
    int arr1[5]={2,1,4,6,3}; 
    int arr2[5]={2,1,5,4,3};
    int i;
    // printf("\nEnter numbers in vector 1: ");
    // for(i = 0; i < n ; i++)
    // {
    //     scanf("%d",&arr1[i]);
    // }
    // printf("\nEnter numbers in vector 1: ");
    // for(i = 0; i < n ; i++)
    // {
    //     scanf("%d",&arr2[i]);
    // }
    sort(arr1, n); 
    sort_des(arr2, n); 
    int sum = 0;
    for(i = 0; i < n ; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }
    printf("\nMinimum scalar product is: ");
    printf("%d",sum);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", time_spent);
    return 0;
}