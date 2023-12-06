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
string Vignere(string PlainText, string key){
    vector<vector<char>> table(26);
    vector<char> temp(26);
    string ans;
    for(int i=0;i<26;i++){
        int count=0;
        for(int j=i;count<26;j=(j+1)%26,count++){
            temp[count] = 'a' + j;
        }
        table[i] = temp;
    }

    for(auto x:table){
        for(auto y:x){
            cout<<y;
        }
        cout<<"-\n";
    }

    int n = key.size();
    int m = PlainText.size();
    int num = m/n;
    int rem = m%n;

    while(--num){
        key+=key;
    }

    key +=  key.substr(0,rem);
    //  cout<<key;

    for(int i=0;i<PlainText.size();i++){
        ans+= table[PlainText[i]-'a'][key[i]-'a'];
    }
    return ans;
}
int main()
{   file();

    string PlainText, CipherText, key;
    cin>>PlainText>>key;

    CipherText = Vignere(PlainText, key);
    cout<<"The Cipher Text is: "<<CipherText<<"\n";

    // string decrypt = Vignere(CipherText, key);
    // cout<<"The Plain Text is: "<<decrypt<<"\n";


    return 0;
}



// abcdefghijklmnopqrstuvwxyz-
// bcdefghijklmnopqrstuvwxyza-
// cdefghijklmnopqrstuvwxyzab-
// defghijklmnopqrstuvwxyzabc-
// efghijklmnopqrstuvwxyzabcd-
// fghijklmnopqrstuvwxyzabcde-
// ghijklmnopqrstuvwxyzabcdef-
// hijklmnopqrstuvwxyzabcdefg-
// ijklmnopqrstuvwxyzabcdefgh-
// jklmnopqrstuvwxyzabcdefghi-
// klmnopqrstuvwxyzabcdefghij-
// lmnopqrstuvwxyzabcdefghijk-
// mnopqrstuvwxyzabcdefghijkl-
// nopqrstuvwxyzabcdefghijklm-
// opqrstuvwxyzabcdefghijklmn-
// pqrstuvwxyzabcdefghijklmno-
// qrstuvwxyzabcdefghijklmnop-
// rstuvwxyzabcdefghijklmnopq-
// stuvwxyzabcdefghijklmnopqr-
// tuvwxyzabcdefghijklmnopqrs-
// uvwxyzabcdefghijklmnopqrst-
// vwxyzabcdefghijklmnopqrstu-
// wxyzabcdefghijklmnopqrstuv-
// xyzabcdefghijklmnopqrstuvw-
// yzabcdefghijklmnopqrstuvwx-
// zabcdefghijklmnopqrstuvwxy-