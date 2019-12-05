//by pter

#include <cstdio>

int main()
{
    int l,r;
    while(true)
    {
         scanf("%d%d", &l, &r);
         if(l == 0 && r == 0)break;
         printf("%d\n",l + r);
    }
    return 0;
}
