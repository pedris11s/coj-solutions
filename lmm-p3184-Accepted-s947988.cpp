#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 5e4 + 7;

int K, D;

LL cd(LL n){
	return ((LL)(log10(K) * n)) + 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> D;

    LL ini = 0, fin = 10000000000000000, sol = 0;
    while(ini <= fin)
    {
        int mit = (ini + fin) / 2;
        int val = cd(mit);
        if(val < D)
            ini = mit + 1;
        else if(val >= D)
            fin = mit - 1, sol = mit;
    }
    cout << sol << "\n";

    return 0;
}

