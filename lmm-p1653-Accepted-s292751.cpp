//by pter

#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXD = 101;

void multdigito(int n[], int d)
{
     int llevo = 0;
     
     for (int i = 1 ; i <= n[0] ; i++)
     {
         n[i] = n[i] * d + llevo;
         llevo = n[i] / 10;
         n[i] %= 10;
     }
     if (llevo > 0)
     {
         n[0] = n[0] + 1;
         n[n[0]] = llevo;
     }
}

int res[MAXD];

int main(){

    int k;
    scanf("%d",&k);
    
    int N;
    for(int ind = 0; ind < k; ind++)
    {
         scanf("%d",&N);

         res[0] = 1;
         res[1] = 1;
    
         for(int i = 0; i < N; i++)
              multdigito(res, 3);         
    
         if(res[1] > 0)
              res[1] -= 1;
         else
         {
              res[1] = 9;
              res[2] -= 1;
         }
    
         for(int j = res[0]; j > 0; j--)
              printf("%d",res[j]);
    
         printf("\n");
    }
    return 0;
}
