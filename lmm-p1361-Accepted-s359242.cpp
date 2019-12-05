#include <cstdio>
#include <cmath>

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF)
        printf("%d\n", (int)sqrt(cbrt(b)) - (int)sqrt(cbrt(a - 1)));

    return 0;
}
