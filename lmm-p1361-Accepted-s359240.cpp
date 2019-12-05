//by pter

#include <cstdio>
#include <cmath>

int f(int n)
{
    return sqrt(cbrt(n));
}

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF)
        printf("%d\n", f(b) - f(a - 1));

    return 0;
}
