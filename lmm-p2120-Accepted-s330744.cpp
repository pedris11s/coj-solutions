#include <cstdio>

bool mk[10];
int TA[5005];

bool is_okay(int n)
{
    for(int i = 0; i < 10; i++)
        mk[i] = false;

    while(n > 0)
    {
        int d = n % 10;
        if(mk[d])
            return false;

        mk[d] = true;
        n /= 10;
    }
    return true;
}

int main()
{
    int n,m;

    for(int i = 1; i <= 5000; i++)
        TA[i] = TA[i - 1] + is_okay(i);

    while(scanf("%d%d", &n, &m) != EOF)
    {
        printf("%d\n", TA[m] - TA[n - 1]);
    }
    return 0 ;
}
