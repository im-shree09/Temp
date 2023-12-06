#include<omp.h>
#include<stdio.h>
int main(){
    double start,end;
    start = omp_get_wtime();

    int na = 12345678, nb = 124,c;
    int a = na,b=nb;
    int rem = 0;
    omp_set_num_threads(nb);
    int ans=0;
    #pragma omp parallel shared(ans,na,nb)
    {
        int tid = omp_get_thread_num();

        tid = tid+1;
        if(na%tid==0 && nb % tid == 0 && tid > ans){
            ans = tid;
        }
    }

    int GCD = ans;
    int LCM = (na * nb)/GCD;

    printf("GCD is %d \n  and the LCM is %d \n", GCD,LCM);


    end = omp_get_wtime();
    printf("The time required for program is %0.8f:",(end-start));

    return 0;
}   