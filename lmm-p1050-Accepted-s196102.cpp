//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int mcd(int u,int v)
{
    return v == 0 ? u : mcd(v, u % v);
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
         int cont = 0;
         for(int i = 1; i < n; i++)
         {
              if(mcd(i,n) == 1)
              cont++;
         }
         
         printf("%d\n",cont);
    }
    return 0;
}
