#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 101;

int main()
{
    int n;
    scanf("%d",&n);
    float a[n];
    float max = -1000000; 
    int index = -1;   
    for(int i = 0; i < n; i++)
    {
         scanf("%f",&a[i]);
         if(a[i] >= max)
         {
              max = a[i];
              index = i;
         }    
    }
    printf("%d\n",index + 1);
    return 0;
}
