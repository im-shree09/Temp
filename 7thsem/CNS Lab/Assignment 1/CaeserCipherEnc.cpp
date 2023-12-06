//code by :- Piyush Mhaske 
// using key and find out the key
#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#define ll long long
#define ul unsigned long long
#define pb emplace_back
#define po pop_back
#define vi vector<ll>
#define vii vector<vector<ll>>
using namespace std;
void file(){    
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);}
ll M = 1e9 + 7;
string caeserCipherEnc(string input, int shift){
    
    for(int i=0;i<input.size();i++){
        char num = input[i] - 'a';

        input[i] = 'a' + (num + shift)%26;
    }
   return input;
}
string caeserCipherDecWithShift(string output, int shift){
    vector<string> ans;
        string temp;
        for(int j=0;j<output.size();j++){
            char num = output[j] - 'a';
            temp += 'a' + (num + (26-shift))%26;
        }
        
        // for(auto x:dictionary){
        //     if(x==temp){
        //         return temp;
        //     }
        // }
        // cout<<temp;

   return temp;
}
vector<string> caeserCipherDec(string output){
    vector<string> ans;
    for(int i=1;i<26;i++){
        string temp;
        for(int j=0;j<output.size();j++){
            char num = output[j] - 'a';
            temp += 'a' + (num + (26-i))%26;
        }
        ans.push_back(temp);
    }
   return ans;
}
int main()
{   file();
    string input;
    cin>>input;

    int shift;
    cin>>shift;

    // encrypt
    string ans = caeserCipherEnc(input,shift);
    cout<<"Encryption of above input: ";
    cout<<ans<<"\n";

    // decrypt
    string dec = caeserCipherDecWithShift(ans,shift);
    cout<<"Decryption of above input: ";
   cout<<dec<<"\n";

    // crack the key
    vector<string> arr = caeserCipherDec(ans);
    cout<<"Decryption of above input: ";
    int i=1;
    for(auto x:arr){
        cout<<"for shift"<<i<<" :";
        cout<<x<<"\n";
        i++;
    }

    return 0;
}