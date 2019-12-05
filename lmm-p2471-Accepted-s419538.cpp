#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

const int MAXN = 100001;

huge N, T;
huge t_task[MAXN];

bool check(huge t)
{
    huge ct = 0;
    for(int i = 0; i < N; i++)
        ct += (t / t_task[i]);

    if(ct >= T)
        return true;
    return false;
}

int main()
{
    //freopen("d.in", "r", stdin);

    scanf("%lld%lld", &N, &T);
    for(int i = 0; i < N; i++)
        scanf("%lld", &t_task[i]);

    huge ini = 1, fin = 1000000000000000000;
    while(fin - ini > 5)
    {
        huge mit = (ini + fin) / 2;
        if(!check(mit))
            ini = mit + 1;
        else
            fin = mit - 1;
    }
    while(!check(ini++));

    cout << ini - 1 << endl;

    return 0;
}
