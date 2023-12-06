#include<stdio.h>
#include<time.h>

// Function to be run on GPU
__global__ void vector_vector(int *a,int *b, int *c, int n){
  int tid = threadIdx.x + blockIdx.x * blockDim.x;

  //checking if thread id is less than n
  if(tid<n){
    c[tid] = a[tid] * b[tid];
  }

}

void init(int * arr, int n, int num){
    for(int i=0;i<n;i++){
        arr[i] = num;
    }
}

bool check(int *a, int *b, int *c, int n){

    for(int i=0;i<n;i++){
        if(c[i] != a[i]*b[i])
        return false;
    }

    return true;

}
int main(int argc, char * argv[]){

    //size of arr;
    int n = 100;

    int *a;
    int *b;
    int *c;

    //calculating the size of arr
    size_t bytes = n * sizeof(int);

    cudaMallocManaged(&a,bytes);
    cudaMallocManaged(&b,bytes);
    cudaMallocManaged(&c,bytes);

    init(a,n,7);
    init(b,n,8);

    size_t threads = 10;
    size_t blocks = n/threads;

    // calling the kernel
    vector_vector<<<threads,blocks>>>(a,b,c,n);

    cudaDeviceSynchronize();

    if(check(a,b,c,n)){
        printf("The output is correct");
    }else{
        printf("Incorrect Output");
    }

    return 0;

}