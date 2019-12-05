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

int t, n, k, rmq[MAX][20];

void create()
{
    for(int i = 1; i < 20; i++)
    {
        for(int j = 0; j < n-(1<<i)+1; j++)
        {
            rmq[j][i] = max(rmq[j][i-1], rmq[j+(1<<(i-1))][i-1]);
        }
    }
}
int query(int a, int b)
{
    if(a>b)swap(a,b);
    int tam = log2(b-a+1);
    return max(rmq[a][tam], rmq[b-(1<<tam)+1][tam]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> rmq[i][0];
        create();
        printf("%d", query(0,k-1));
        for(int i = 1; i + k - 1< n; i++)
        {
            printf(" %d", query(i, i+k-1));
        }
        printf("\n");
    }

    return 0;
}
