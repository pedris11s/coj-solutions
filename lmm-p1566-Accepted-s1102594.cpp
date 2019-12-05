#include <cstdio>
int ans, n;
int main()
{
    while (scanf("%d", &n))
    {
        if (!n) break;
        ans = 0;
        for (int i = n; i >= 1; i--)
                ans += i*i;
        printf ("%d\n", ans);
    }
return 0;    
}