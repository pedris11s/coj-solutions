#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

vector <ll> v;

void baseM2(ll n)
{
    if(n == 0 || n == 1 )
    {
        v.push_back(n);
        //printf("%d ", n);
        return;
    }
    if(n & 1)
    {
        v.push_back(1);
        //printf("%d ", (n - 1) / (-2) );
        baseM2( (n - 1) / (-2) );
    }
    else
    {
        v.push_back(0);
        //printf("%d ", n / (-2) );
        baseM2(n / (-2) );
    }
}

int main()
{
    ll t;
    cin >> t;

    ll n;
    for(int i = 1; i <= t; i++)
    {
        cin >> n;
        v.clear();
        baseM2(n);
        reverse(v.begin(), v.end());
        cout << "Case #" << i << ": ";
        for(int j = 0; j < v.size(); j++)
            cout << v[j];

        printf("\n");
    }

    return 0;
}
