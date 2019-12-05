//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    
    long long hex;
    
    for(int i = 0; i < t; i++)
    {
         scanf("%llx",&hex);
         if(hex % 2 == 1)
              printf("YES\n");
         else 
              printf("NO\n");
    }
    return 0;
}
