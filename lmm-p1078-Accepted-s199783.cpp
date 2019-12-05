//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int T,N,An;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
         scanf("%d",&N);
         int sum = 0;
         for(int j = 0; j < N; j++)
         {
              scanf("%d",&An);
              sum += An;
         }
         if(sum % N == 0)
              printf("YES\n");
         else
              printf("NO\n");     
    }
    return 0;
}
