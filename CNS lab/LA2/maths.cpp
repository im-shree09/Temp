#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class menu
{
    public : 
   long long find_multiplicative_inverse(long long a, long long b) {
    long long q, r, t1 = 0, t2 = 1, t, main_a = a;
cout<<"\n___________________________________________________________________________________________________________________________________________\n";
    cout << "|\tQ\t|\tA\t|\tB\t|\tR\t|\tT1\t|\tT2\t|\tT\t|\n";
  cout<<"\n___________________________________________________________________________________________________________________________________________\n";
    

    while (b > 0) {
        q = a / b;
        r = a % b;
        t = t1 -  (t2 * q );
        cout << "|\t" << q << "\t|\t" << a << "\t|\t" << b << "\t|\t" << r << "\t|\t" << t1 << "\t|\t" << t2 << "\t|\t" << t << "\t|\n";
      cout<<"\n___________________________________________________________________________________________________________________________________________\n";

        a = b;
        b = r;
        t1 = t2;
        t2 = t;
    }

    cout << "|\t" << q << "\t|\t" << a << "\t|\t" << b << "\t|\t" << r << "\t|\t" << t1 << "\t|\t" << t2 << "\t|\t" << t << "\t|\n";
    cout<<"\n___________________________________________________________________________________________________________________________________________\n";

    if (t1 < 0) {
        t1 += main_a;
    }
    return t1;
}

    long long find_large_number_gcd(long long a,long long b)
    {
        long long q,r;
            cout<<"\n___________________________________________________________________________________________________________________________________________\n";
            cout<<"|\t\tQ\t\t|\t\tA\t\t|\t\tB\t\t|\t\tR\t\t|\n";
          cout<<"\n___________________________________________________________________________________________________________________________________________\n";

            while(b>0)
            {
                    q=a/b;
                    r=a%b;
                    cout<<"|\t\t"<<q<<"\t\t|\t\t"<<a<<"\t\t|\t\t"<<b<<"\t\t|\t\t"<<r<<"\t\t|\n";
                 cout<<"\n___________________________________________________________________________________________________________________________________________\n";
                    a=b;
                    b=r;
            }
             cout<<"|\t\t"<<q<<"\t\t|\t\t"<<a<<"\t\t|\t\t"<<b<<"\t\t|\t\t"<<r<<"\t\t|\n";
    cout<<"\n___________________________________________________________________________________________________________________________________________\n";

            cout<<endl;
            
            return a;
    }
 

};
int main()
{
    main_menu:
    cout<<"\n________________________________________________________________________________\n";
    cout<<"\n1.Find Multiplicative Inverse (Extended Euclidien Algo ) \n2.Find GCD Of large numbers(Euclideian Algo ) \n";
    cout<<"________________________________________________________________________________\n";
    cout<<"Enter Choice Code :\t";
    menu object;
    int ch;
    cin>>ch;
    cout<<"\n";
    long long a,b,ans;
    
    switch(ch)
    {
        case 1 :
            
            cout<<"\nEnter  A and B ( must be A>B)  :\t";
            cin>>a>>b;
            ans=object.find_multiplicative_inverse(a,b);
            cout<<"Multiplicative Inverse Of  "<<a<<"\tAnd "<<b<<"\t :\t"<<ans<<endl;
            goto main_menu;

        case 2:
           
            cout<<"\nEnter  A and B  :\t";
            cin>>a>>b;
             ans=object.find_large_number_gcd(a,b);
            cout<<"\nGCD Of   Of  "<<a<<"\tAnd "<<b<<"\t :\t"<<ans<<endl;
            goto main_menu;


       
        default: 
            cout<<"Invalid Input !";
            break;
    }

    return 0;
}