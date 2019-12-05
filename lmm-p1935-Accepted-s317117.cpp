#include <cstdio>

int main()
{
    int v,t;
    while(scanf("%d%d", &v,&t) != EOF)
    {
        int desp = 2 * (v) * (t);
        printf("%d\n", desp);
    }

    return 0;
}
