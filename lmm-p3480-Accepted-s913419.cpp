#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1500;

const int MOD = 1000;

LL fib[MAXN], sum[MAXN];

int main()
{
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i < MAXN; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;

    for(int i = 1; i < MAXN; i++)
        sum[i] = sum[i - 1] + fib[i];

    LL SUM = sum[1499];

    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL a, b;
        scanf("%lld%lld", &a, &b);

        LL sumb = SUM * (b / 1500) + sum[b % 1500];
        LL suma = SUM * ((a - 1) / 1500) + sum[(a - 1) % 1500];
        LL sol = sumb - suma;

        printf("%lld\n", sol);
    }
    return 0;
}
