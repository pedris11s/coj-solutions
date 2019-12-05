#include<bits/stdc++.h>
using namespace std;
int n , cont;
int main()
{
    cin>>n;
   
       for(int i = 1 ; i <= n ; i += 3 )
           cont++;   
       

       cout<<n - cont<<"\n";
     

    return 0;
}
