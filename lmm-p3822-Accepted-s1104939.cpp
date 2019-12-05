#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e4 + 7;

bool comp[MAXN];

void criba(){
    comp[1] = true;
    for(int i = 4; i < MAXN; i += 2)
        comp[i] = true;

    for(int i = 3; i * i < MAXN; i += 2)
        if(!comp[i])
            for(int j = i * i; j < MAXN; j +=  2 * i)
                comp[j] = true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    criba();

    int N;
    cin >> N;
    int cont = 0;
    for(int i = 1; i <= N; i++){
        int x = __gcd(i, N);
        if(!comp[x])
            cont++;
    }
    cout << cont << "\n";
    return 0;
}
