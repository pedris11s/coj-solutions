//by pter

#include <cstdio>

const int MAXN = 10002;

bool mk[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    int n;
    int cont = 0;
    for(int i = 0; i < t; i++)
    {
         scanf("%d", &n);
         if (n > t)
            cont++;
         else
         if(!mk[n])
              mk[n] = true;
         else
              cont++;
    }
    printf("%d\n",cont);
    return 0;
}
