//by pter

#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int t;
    char n[1001];
     
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
         scanf("%s",n);
         int size = strlen(n);
 
         if(n[size - 1] & 1)
              printf("NO\n");
         else
         {
              int sum = 0;
              
              for(int i = 0; i < size; i++)
                   sum += n[i] - 48;   
              
              if(sum % 3 == 0)
                   printf("YES\n");
              else
                   printf("NO\n"); 
         }    
    }
    return 0;
}
