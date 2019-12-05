//by pter

#include <cstdio>

int modulo(int n)
{
    if(n >= 0)
         return n;

    return n * -1;
}

int main()
{
    int k;
    scanf("%d",&k);
    int x1,y1,x2,y2;
    for(int i = 0; i < k; i++)
    {
         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
         int MD = modulo(x2 - x1) + modulo(y2 - y1);
         printf("%d\n",MD);
    }
    return 0;
}
