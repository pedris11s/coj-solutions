//by pter

#include <cstdio>
#include <cstring>

int main()
{
    char n1[101];
    char n2[101];
    
    while(true)
    {
         scanf("%s",n1);
         if(n1[0] == 'X')
              break;
              
         int size = strlen(n1);
         scanf("%s",n2);
         int hd = 0;
         for(int i = 0; i < size; i++)
         {
              if(n1[i] != n2[i])
                   hd++;
         }
         printf("Hamming distance is %d.\n",hd);
    }
    return 0;
}
