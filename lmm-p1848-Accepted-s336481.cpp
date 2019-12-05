//by pter

#include <cstdio>

const int MOD = 10000;
const int MAX = 10001;

int Fib[MAX];

int main()
{
    int t,n;
    scanf("%d", &t);

    Fib[0] = 0;
    Fib[1] = 1;

    for(int i = 2; i < MAX; i++)
        Fib[i] = ((Fib[i - 1] % MOD) + (Fib[i - 2] % MOD)) % MOD;

    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%d %d %d\n", Fib[n - 2], Fib[n - 1], Fib[n]);
    }

    return 0;
}
