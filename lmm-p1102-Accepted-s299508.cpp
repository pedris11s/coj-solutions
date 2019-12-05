//by pter

#include <cstdio>
#include <cstring>

int modulo(int n)
{
    if(n >= 0)
         return n;    
    else
         return n * -1;
}

int main()
{
    char n[1001];
    while(true)
    {
         scanf("%s",&n);
         int size = strlen(n);
         
         if(n[0] == '0' && size == 1)            
              break;
         
         int sumP = 0, sumI = 0;
         for(int i = 0; i < size; i++)
              if(i & 1)
                        sumI += n[i] - 48;
                   else
                        sumP += n[i] - 48;
         
         int value = modulo(sumP - sumI);

         if(value == 0)
              printf("%s is a multiple of 11.\n",n);
         else if(value % 11 == 0)
                   printf("%s is a multiple of 11.\n",n);
              else 
                   printf("%s is not a multiple of 11.\n",n);
    }
    return 0;
}
