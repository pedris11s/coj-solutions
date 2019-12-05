#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

const int MAXN = 1000005;

#define MOD 10000

int N, U, Q;
huge tree[MAXN];

void update(int pos, int value)
{
    for(int i = pos; i <= N; i += (i & -i))
        tree[i] += value;
}

huge query(int pos)
{
    huge sum = 0;
    for(int i = pos; i > 0; i -= (i & -i))
        sum += tree[i];
    return sum;
}

int main()
{
    scanf("%d%d%d", &N, &U, &Q);
    for(int i = 0; i < U + Q; i++)
    {
        int uq, a, b;
        scanf("%d%d%d", &uq, &a, &b);
        if(uq == 1)
        {
            if(a != 1)update(a - 1, b);
            update(a, 2 * b);
            if(a != N)update(a + 1, b);
        }
        else
        {
            huge sol = (huge)query(b) - (huge)query(a - 1);
            printf("%lld\n", sol % MOD);
         }
    }

    return 0;
}
