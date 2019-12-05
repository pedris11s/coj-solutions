#include <cstdio>

int main()
{
    int n;
    while(true)
    {
         scanf("%d",&n);
         if(n == -1)break;
         int pi;
         int cantV = 0;
         int sum = 0;
         for(int i = 0; i < n; i++)
         {
              
              scanf("%d",&pi);
              sum += pi;
              if(sum % 100 == 0)
              {
                   sum -= 100;
                   cantV++;
              }    
         } 
         printf("%d\n",cantV);
    }
    
    return 0;
}
