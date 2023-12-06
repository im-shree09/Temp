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
string Decrypt(string CipherText, string key){
    unordered_map<int,vector<char>> mp;
    int n = key.size();
    int m = CipherText.size();
    string ans="";

    int col = m/n;
    int rem = m%n;
    vector<int> len(key.size(),col);
    if(rem!=0){
         for(int i=0;i<n;i++){
            if(rem>0){
                len[i] = col+1;
            }else{
                len[i] = col;
            }
            rem--;
        }
    }else{
          for(int i=0;i<n;i++)
         len[i] = col;
    }
   
   vector<pair<char,int>> temp;
   for(int i=0;i<n;i++){
    temp.push_back({key[i],i});
   }

   sort(temp.begin(),temp.end());
   
    int i=0;
    for(auto x:temp){
        while(len[x.second]--){
            // cout<<len[x.second];
        mp[x.second].push_back(CipherText[i]);
        i++;
        }
    }
     
     for(int i=0;i<key.size();i++){
        cout<<key[i]<<": ";
        for(auto x: mp[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
     }


    int j=0,k=0;
    while(j<CipherText.size()){
        for(int i=0;i<key.size();i++){
            // cout<<key[i]<<": ";
            ans+=mp[i][k];
        }
        k++;
        j++;
    }

    
    return ans;
}
string Columnar(string PlainText, string key){
    string ans;
    unordered_map<char,vector<char>> mp;
    vector<pair<char,int>> temp;

    for(int i=0;i<key.size();i++){
        temp.push_back({key[i],i});
    }

    sort(temp.begin(),temp.end());

    int j=0;
    int m = key.size();
    for(int i=0;i<PlainText.size();i++){
        mp[j].push_back(PlainText[i]);
        j = (j+1)%m;
    }

    for(auto x:temp){
        if(mp.count(x.second)){
            cout<<x.first<<": ";
            for(auto y:mp[x.second]){
                cout<<y;
                ans+=y;
            }
            cout<<"\n";
        }
    }

    return ans;

}
int main()
{   file();
    string PlainText, CipherText, key;
    cin>>PlainText>>key;

    CipherText = Columnar(PlainText, key);
    cout<<"The Encrypted text is: "<<CipherText<<"\n";

    cout<<"Decrytping\n";
    string decrypt = Decrypt(CipherText, key);
    decrypt = decrypt.substr(0,CipherText.size());
    cout<<"The decrypt text is : "<<decrypt<<"\n";
    return 0;
}