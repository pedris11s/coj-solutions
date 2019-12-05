#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e15;

long long f[5007];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    f[0] = 1;
    for(int i = 1; i <= 5000; i++){
        f[i] = f[i - 1] * i;
        while(f[i] % 10 == 0)
            f[i] /= 10;

        f[i] %= MOD;
    }/*
    for(int i = 6; i <= 15; i++){
        cout <<i << ") "<<  f[i] << endl;
    }*/
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << f[n] % 10 << "\n";
    }


    return 0;
}
