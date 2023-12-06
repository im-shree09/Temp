//code by :- Piyush Mhaske 
#include <bits/stdc++.h>
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
string RailFence(int key, string input){
     int n = input.length();
    vector<vector<char>> rail(key,vector<char>(n,'#'));
   int depth=0;
   bool good=true;
    for(int i=0;i<n;i++){
            // cout<<depth;
            rail[depth][i] = input[i];
             if(good){
                depth++;
            }else{
                depth--;
            }
             if(depth==0){
                good=true;
            }else if(depth==key-1){
                good=false;
            }
    }


    string ans="";

    for(int i=0;i<key;i++){
        for(int j=0;j<n;j++){
            cout<<rail[i][j];
            if(rail[i][j]!='#')
            ans += rail[i][j];
        }
        cout<<"\n";
    }
    
    return ans;

}
int main()
{   file();
    int key;
    string input;
    cin>>key>>input;

    string ans = RailFence(key,input);
    cout<<"Encryption of above input: ";
    cout<<ans<<"\n";

    return 0;
}