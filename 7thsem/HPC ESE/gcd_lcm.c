#include<stdio.h>

int main(){
    double start,end;
    start = clock();

    int na = 64, nb = 12,c;
    int a = na,b=nb;
    int rem = 0; 
        for(int i = b;i>0; i-- ){
            c = a%b;
            a = b;
            b = c;
            if(b==0) i=0;
        }

    int GCD = a;
    int LCM = (na * nb)/GCD;

    printf("GCD is %d \n  and the LCM is %d \n", GCD,LCM);


    end = clock();
    printf("The time required for program is %0.8f:",(end-start));

    return 0;
}   