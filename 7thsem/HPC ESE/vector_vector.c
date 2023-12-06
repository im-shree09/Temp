#include<stdio.h>
#include<time.h>
void init(int * arr, int n, int num){
    for(int i=0;i<n;i++){
        arr[i] = num;
    }
}

void vector_vector(int *a, int *b, int *c, int n){

    for(int i=0;i<n;i++){
        c[i] = a[i] * b[i];
    }

}
int main(int argc, char * argv[]){

    //size of arr;
    int n = 100000000;

    double start,end;
    start = clock();

    int *a;
    int *b;
    int *c;

    //calculating the size of arr
    size_t bytes = n * sizeof(int);
    a = (int *)malloc(bytes);
    b = (int *)malloc(bytes);
    c = (int *)malloc(bytes);


    init(a,n,7);
    init(b,n,8);
    // calling the kernel
    vector_vector(a,b,c,n);
    end = clock();

    printf("The time required is %0.8f ",(end-start));

    return 0;

}