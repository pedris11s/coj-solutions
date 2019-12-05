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
typedef complex<double> P;
const int MAX = 1e6 + 5;

 int t, cant[300], pos, l;
 char cad[1005], pal[1005];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    ll x;
    cin>>t;
    while(t--)
    {
        cin >> l >> cad + 1;
        memset(cant, 0, sizeof(cant));
        memset(pal, 0, sizeof(pal));
        pos = 0;
        for(int i = 1; i <= l; i++)
            cant[cad[i]]++;
        bool imp = false;
        for(int i = 'A'; i <= 'Z'; i++) {
            for(int j = 1; j <= cant[i] / 2; j++)
                pal[pos++] = (char)i;
        }
        for(int i = 'A'; i <= 'Z'; i++) {
            if(cant[i] & 1)
            {
                imp = true;
                pal[pos++] = (char)i;
                break;
            }
        }
        if(imp)pos--;
        int tam = 2 * pos + imp;
        for(int i = 0; i < pos; i++) {
            pal[tam-i-1] = pal[i];
        }
        cout << pal << "\n";
    }

    return 0;
}

