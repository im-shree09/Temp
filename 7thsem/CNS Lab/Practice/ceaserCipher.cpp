#include<bits/stdc++.h>

using namespace std;
int main(){
    string str;
    cin>>str;
    int shift;
    cin>>shift;

    string ans="";
    for(int i=0;i<str.length();i++){
        int j = str[i] - 65;
        ans += 'a' + (j + shift)%26;
    }

    cout<<ans;

}