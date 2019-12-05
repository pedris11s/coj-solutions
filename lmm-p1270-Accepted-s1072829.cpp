#include <bits/stdc++.h>

using namespace std;

double X, Y;
long long a, b;

int main()
{
   //ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>X; cin>>Y;
   a = X * 1e9 + 0.2;
   b = Y * 1e9 + 0.2;
   
   cout<<a / b<<'\n';
   //return 0;
}