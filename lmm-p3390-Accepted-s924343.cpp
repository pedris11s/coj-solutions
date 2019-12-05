#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i,a,b)  for(int i = a; i < b; i++)
using namespace std;

typedef long long ll;
const ll MOD = 1000003;
#define MAXN 100005

int n;
int arr[MAXN];
int main()
{
    SD(n);
    int maxi = 0;
    int mini = INT_MAX;
    FOR(i, n)
    {
        SD(arr[i]);
    }
    sort(arr,arr+n);
    mini = arr[0];
    bool ok = true;
    bool primero = true;
    FOR(i, n)
    {
        if(arr[i]<i+1)
        {
            ok = false;
            break;
        }
    }
    if(!ok)
    {
        printf("S\n");
        return 0;
    }
    int val = ((mini/(n+1))*2)%2;
    if(val==1)
    {
        primero = false;
    }
    int turnos = mini%(n+1);
    int quitar = mini-turnos;
    FOR(i, n)
    {
        arr[i]-=quitar;
    }
    FOR(i, n)
    {
        if(arr[i]<i+1)
        {
            ok =false;
            break;
        }
    }
    if(primero)
    {
        if(ok)
        {
            printf("N\n");
        }else{
            printf("S\n");
        }
    }else{
        if(ok)
        {
            printf("S\n");
        }else{
            printf("N\n");
        }
    }

    return 0;
}
