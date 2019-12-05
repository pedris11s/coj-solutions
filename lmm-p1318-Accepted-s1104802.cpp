#include <bits/stdc++.h>

using namespace std;

int ar[5];
string cad;

int main()
{
    cin>>ar[0]>>ar[1]>>ar[2];

    cin>>cad;
    sort(ar , ar +3);

    cout<<ar[cad[0] - 'A']<<" "<<ar[cad[1] - 'A']<<" "<<ar[cad[2] - 'A']<<"\n";
    return 0;
}
