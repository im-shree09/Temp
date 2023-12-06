#include<bits/stdc++.h>

using namespace std;

int gcd(int x, int y, int *t1, int *t2){

    cout<<x<<" "<<y<<" "<<*t1<<" "<<*t2<<"\n";
    if(y==0){
        return *t1;
    }

    int q = x/y;
    int x1 = *t2;
    int x2 = (*t1 - (q*(*t2)));
    int inv = gcd(y,x%y,&x1,&x2);

    return inv;

}

int main(){
    int x=64,y=17, t1 = 0,t2 = 1;
    int inv = gcd(x,y,&t1,&t2);
    while(inv < 0) inv = x + inv;
    cout<<inv;

}