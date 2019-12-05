#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d", &n,&m)
#define SS(n) scanf("%s", n)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i,a,b) for(int i = a; i < b; i++)
#define FORR(i, n) for(int i = n; i >= 0; i--)
#define zero(n) memset(n,0,sizeof(n))
#define mone(n) memset(n,-1,sizeof(n))
//typedef complex<double> P;

const int MAX = 1e5 + 5;
const int mod = 1e9 + 7;

int t, n;
map <int, int> m;
map <int, int> :: iterator ite;
int lista[MAX], reord[MAX];
int par[MAX], impar[MAX];

int query1(int k) { //pares
    int ret = 0;
    for(int i = k; i != 0; i ^= i & -i)
        ret = (ret + par[i]) % mod;
    return ret;
}

int query2(int k) { //pares
    int ret = 0;
    for(int i = k; i != 0; i ^= i & -i)
        ret = (ret + impar[i]) % mod;
    return ret;
}

void update1(int pos, int val) {
    for(int i = pos; i < MAX; i += i & -i)
        par[i] = (par[i] + val) % mod;
}

void update2(int pos, int val) {
    for(int i = pos; i < MAX; i += i & -i)
        impar[i] = (impar[i] + val) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> t;
    while(t--) {
        cin>> n;
        for(int i = 1; i <= n; i++) {
            cin >> lista[i];
            m[lista[i]] = 0;
        }
        int cont = 0;
        for(ite = m.begin(); ite != m.end(); ite++)
            ite -> second = ++cont;
        for(int i = 1; i <= n; i++) {
            reord[i] = m[lista[i]];
        }
        for(int i = 1; i <= n; i++) {
            if(lista[i] & 1) {
                update2(reord[i], 1 + query1(reord[i] - 1));
                update1(reord[i], query2(reord[i] - 1));
            }
            else {
                update1(reord[i], 1 + query1(reord[i] - 1));
                update2(reord[i], query2(reord[i] - 1));
            }
        }
        cout << query2(cont) << "\n";
        memset(par, 0, sizeof(par));
        memset(impar, 0, sizeof(impar));
        m.clear();
    }

    return 0;
}
