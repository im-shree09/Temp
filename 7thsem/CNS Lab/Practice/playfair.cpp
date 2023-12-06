#include<bits/stdc++.h>

using namespace std;

int main(){
    
    string key, message;
    cin>>key;
    cin>>message;

    vector<int> arr(26,0);

    vector<vector<char>> mat(5,vector<char>(5));

    for(int i=0;i<key.length();i++){
        if(arr[key[i]-'a']==0){
               mat[i/5][i%5] = key[i];
               if(key[i]=='j' || key[i]=='i'){
                 arr['j'-'a'] = 1;
                 arr['i'-'a'] = 1;
               }
               arr[key[i]-'a'] = 1;
        }
    }
    int j=0;
    for(int i=key.length();i<25;i++){
        while(arr[j]==1) j++;
         mat[i/5][i%5] = key[i];
         j++;
         
    }

}