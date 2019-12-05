//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t,cn,n;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
         int oddC = 0;
         scanf("%d",&cn);
         for(int j = 0; j < cn; j++)
         {
              scanf("%d",&n);
              if(n & 1)
                   oddC++;
         }
         printf("%d even and %d odd.\n",cn - oddC,oddC);
    }    
    return 0;
}
