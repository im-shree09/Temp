#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string binary;
    cin>>binary;
    reverse(binary.begin(),binary.end());
    int num=0;
    for(int i=0;i<binary.size();i++)   if(binary[i]=='1') num+=pow(2,i);
    cout<<num;
    
    return 0;
}