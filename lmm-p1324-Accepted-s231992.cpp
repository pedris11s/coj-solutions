//by pter

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int a[9];
    int sum = 0;
    int n1,n2;
    for(int i = 0; i < 9; i++)
    {
         scanf("%d",&a[i]);
         sum += a[i];
    }
    
    sum -= 100; 
    
    for(int i = 0; i < 8; i++)
         for(int j = i + 1; j < 9; j++) 
              if(sum == (a[i] + a[j]))
              {
                   n1 = a[i];
                   n2 = a[j];
              }
              
    sort(a,a + 9);
    
    for(int i = 0; i < 9; i++)
          if(a[i] != n1 && a[i] != n2)
               printf("%d\n",a[i]);

    return 0;
}
