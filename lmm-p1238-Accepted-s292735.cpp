//by pter

#include <cstdio>
#include <cstring>

using namespace std;

int fact(int n)
{
    if(n == 0 || n == 1)
         return 1;
    
    return n * fact(n - 1); 
}

int main()
{
    char n[10];
    
    while(true)
    {
         scanf("%s",n);      
         int size = strlen(n);
         
         if(n[0] == '0' && size == 1)
              break;
         
         int sum = 0;
         for(int i = 0; i < size; i++) 
              sum += (n[i] - 48) * fact(size - i);
         
         printf("%d\n",sum);    
    }
    return 0;
}
