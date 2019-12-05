#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 10000;


int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string cad;
    cin >> cad;
    int p = 1;
    for(int i = 0; i < cad.size(); i++){
        p *= (cad[i] - 'A' + 1);
        p %= 26;
    }
    if(p < 10)
        cout <<"0";
    cout << p << '\n';

    return 0;
}


