#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
const ll MOD = 1000003;
#define MAXN 1000005

char cad[55];
vector<int> pilas;
int main()
{
    scanf("%s", cad);
    int len = strlen(cad);
    bool ok = false;
    int nim = 0;
    FOR(i, len)
    {
        if(cad[i]=='#')
        {
            ok = true;
            pilas.pb(nim);
            nim = 0;
        }else{
            nim++;
        }
    }
    if(!ok)
    {
        printf("Rabbit\n");
    }else{
        pilas.pb(nim);
    int sg = 0;
    FOR(i, pilas.size())
    {
        sg^=pilas[i];
    }
    if(sg)
    {
        printf("Cat\n");
    }else{
        printf("Rabbit\n");

    }
    }



    return 0;
}
