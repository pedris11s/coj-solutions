#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

LL MOD;

int main()
{
    int t;
    cin >> t >> MOD;
    while(t--)
    {
        LL N;
        cin >> N;
        LL sol = ((N % MOD) * (N % MOD)) % MOD;
        cout << sol << endl;
    }



    return 0;
}

