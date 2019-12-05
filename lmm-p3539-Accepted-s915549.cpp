#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1000007;

LL N, W, A[MAXN];

bool sol(LL n)
{
    LL sum = 0;
    for(int i = 0; i < N; i++)
        if(A[i] - n > 0)
            sum += A[i] - n;
    if(sum >= W)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> W;

    LL maximo = -1;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        maximo = max(maximo, A[i]);
    }

    LL ini = 1, fin = maximo;
    while(fin - ini >= 5)
    {
        LL mit = (ini + fin) / 2;
        if(sol(mit))
            ini = mit;
        else
            fin = mit - 1;
    }
    while(!sol(fin--));

    cout << fin + 1 << "\n";


    return 0;
}
