#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
#define MAXN 1000005
ll n;
bool visited[MAXN];

void criba()
{
    for(int i= 2; i*i < MAXN; i++)
    {
        if(!visited[i])
        {
            for(int j = i*i; j < MAXN; j+=i)
            {
                visited[j] = true;
            }
        }
    }
}
int primos[MAXN];
int cont = 0;
int main()
{
    ios_base :: sync_with_stdio(0); cin.tie(0);
    criba();
    visited[0] = visited[1] = visited[2] =  true;
    for(int i = 3; i < MAXN; i++)
    {
        if(!visited[i])
        {
            primos[cont] = i;
            cont++;
        }
    }
    while(true)
    {
        scanf("%d", &n);
        if(!n) break;
        int maxi = -1;
        int val1 = 0,val2= 0;
        bool ok = false;
        for(int i = 0; i < cont; i++)
        {
            int primo = primos[i];
            if(primo>=n) break;
            int v1 = n-primo;
            if(!visited[v1])
            {
                int val = v1-primo;
                if(val>maxi)
                {
                    ok = true;
                    val1 = primo;
                    val2 = v1;
                    maxi = val;
                }
            }
        }
        if(!ok)
        {
            cout << "Goldbach's conjecture is wrong." <<'\n';
        }else{
            cout << n<<" = "<<val1 << " + "<<val2<<'\n';
        }
    }



    return 0;
}
