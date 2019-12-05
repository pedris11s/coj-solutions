#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll myRev(ll n)
{
    ll num = 0;
    while(n > 0)
    {
        num = num * 10 + n % 10;
        n /= 10;
    }
    return num;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector <ll> v;
    for(int i = 0; i < n; i++)
    {
        ll num;
        scanf("%lld", &num);
        v.push_back(myRev(num));
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++)
        printf("%lld\n", v[i]);

    return 0;
}


