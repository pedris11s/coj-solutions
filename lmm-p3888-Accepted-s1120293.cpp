#include <bits/stdc++.h>

using namespace std;


typedef long long LL;

LL A, B, a, b;

LL sol(LL n, LL k){
    LL cont = 0;
    while(true){
        if(k > n)return INT_MAX;
        if(k == n) return cont;

        if(k >= (n + 1) / 2){
            cont++;
            return cont;
        }

        cont++;
        n = (n + 1) / 2;
    }
    return cont;
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> A >> B >> a >> b;
    LL v1 = sol(A, a) + sol(B, b);
    LL v2 = sol(A, b) + sol(B, a);
    LL val = min(v1, v2);
    if(val >= INT_MAX)
        cout << "-1\n";
    else
        cout << val << "\n";

    return 0;
}
