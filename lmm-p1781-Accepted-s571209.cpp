#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

LL TA[10004];

int main()
{
    //freopen(".in", "r", stdin);
    int N, U;
    cin >> N >> U;
    for(int i = 0; i < U; i++)
    {
        LL ci;int ri;
        cin >> ci >> ri;
        TA[ri] += ci;
    }
    for(int i = 1; i <= N; i++)
        TA[i] += TA[i - 1];

    int Q;
    cin >> Q;
    while(Q--)
    {
        int k;
        cin >> k;

        int ini = 1, fin = 1;
        LL sol = (1LL << 62) - 1;
        for(int i = k; i <= N; i++)
            if(TA[i] - TA[i - k] < sol)
            {
                sol = TA[i] - TA[i - k];
                ini = i - k + 1;
                fin = i;
            }
        cout << ini << ' ' << fin << ' ' << sol << endl;

    }


    return 0;
}
