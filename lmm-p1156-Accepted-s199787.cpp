//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    
    while(scanf("%d",&n) != EOF)
    {
         if(n != 42)
              printf("%d\n",n);
         else
              break;
    }
    return 0;
}
