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

   /* int sol = 0;
for(int i =2; i < MAXN; i++)
    if(!comp[i])
    sol++;
cout << sol << endl;*/

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    int sol = -1;
    int cas = 1;
    while(t--){
        int sum = 0;
        int x = 0; int m = 10000, M = -1;
        for(int i = 0; i < 10; i++){
            cin >> x;
            sum += x;
            m = min(m, x);
            M = max(M, x);
        }
        sum -= (m + M);
        sol = max(sum, sol);
        cout << cas++ << " " << sum << "\n";
    }
    cout << sol << "\n";

    /*criba();

    int N;
    cin >> N;
    int cont = 0;
    for(int i = 2; i <= N; i++){
        int x = __gcd(i, N);
        if(!comp[x])
            cont++;
    }
    cout << cont << "\n";*/
    return 0;
}
