#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;
const int MOD = 1000007;

int P[MAXN];

int Calc(int n)
{
    return (P[n + 1] - 1 + MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    P[0] = 1;
    for(int i = 1; i < MAXN; i++){
        P[i] = P[i - 1] * 2;
        P[i] %= MOD;
    }


    while(true)
    {
        int a, b, aa, bb;
        cin >> a >> b;
        if(a == -1)break;


        if(a == 0)
            aa = 0;
        else
            aa = Calc(a - 1);
        bb = Calc(b);

        int sol = (bb - aa + MOD) % MOD;
        cout << sol << "\n";
    }


    return 0;
}
