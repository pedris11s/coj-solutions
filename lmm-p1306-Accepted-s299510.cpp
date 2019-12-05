//by pter

#include <cstdio>
#include <cstring>

int main()
{
    int t;
    scanf("%d",&t);
    char a[101];
    for(int i = 0; i < t; i++)
    {
         scanf("%s",a);
         int size = strlen(a);
         int lastD = ((a[size - 2] - 48) * 10) + (a[size - 1] - 48);
         
         if(lastD == 0)
              printf("YES\n");
         else if(lastD % 4 == 0)
                   printf("YES\n");
              else
                   printf("NO\n");   
    }
    return 0;
}
