#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int sort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
             if (arr[j] > arr[j+1]){
                int temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
        }
    }
    
}

int sort_des(int arr[], int n){
    int i,j;
    for (i = 0; i < n; ++i){
        for (j = i + 1; j < n; ++j){
            if (arr[i] < arr[j]){
            int a = arr[i]; arr[i] = arr[j]; arr[j] = a;
            }
        }
    }
}

int main(){
    //fill the code; int n;
    double startTime=omp_get_wtime();  
    int n;
    scanf("%d",&n);
    int arr1[n], arr2[n]; int i;
    for(i = 0; i < n ; i++){
        scanf("%d",&arr1[i]);
    }
    for(i = 0; i < n ; i++){
        scanf("%d",&arr2[i]);
    }

#pragma omp parallel
{
    sort(arr1, n); 
    sort_des(arr2, n); 
}

    
    int sum = 0;

    for(i = 0; i < n ; i++){
        sum = sum + (arr1[i] * arr2[i]);
    }
    printf("%d",sum);
    double endTime=omp_get_wtime();
    double seq_time = endTime-startTime;
    printf("\n the Speed Up is : %lf",seq_time);
    return 0;
}

// void main(){
//     printf("Hello World\n");
// #pragma omp parallel
//     {
//         printf("Hello From thread Number %d\n", omp_get_thread_num());
//     }
// }