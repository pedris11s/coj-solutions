#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    LL a, b;
    while(scanf("%lld%lld", &a, &b))
    {
        if(a == 0 && b == 0)
            break;

        if(b - a + 1 == 1)
        {
            LL sq = sqrt(a);
            if(sq * sq == a)
            {
                printf("0\n");
                continue;
            }
        }

        LL tsq =(LL)sqrt(b) - (LL)sqrt(a);
        LL SOL = (b - a) + 1 - tsq;
        LL sq = sqrt(a);

        if(sq * sq == a || a == 1)
            SOL--;

        printf("%lld\n", SOL);
    }



    return 0;
}
