//by pter.last one

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 1001;

char aux[MAXN];

void Sum_Bin(int n[])
{
    int sol[n[0]];
    sol[0] = n[0];
    int llevo1 = 0;
    int j = strlen(aux) - 1;
    for(int i = 1; i < sol[0]; i++)
    {
         if(j < 0)
              sol[i] = n[i] + llevo1;         
         else
         {
              sol[i] = n[i] + (aux[j] - 48) + llevo1; 
              j--;        
         }    
         llevo1 = sol[i] / 2;
         sol[i] %= 2;               
    }
    if (llevo1 > 0)
    {
         sol[0]++;
         sol[sol[0] - 1] = llevo1 % 2;
    }
    for(int i = sol[0] - 1; i > 0; i--)
         printf("%d",sol[i]);

    printf("\n");
} 

int main()
{
    scanf("%s",aux);
    
    int size = strlen(aux) + 5;

    int n[size];
    n[0] = size;
    int j = strlen(aux) - 1;
    
    for(int i = 1; i < n[0]; i++)
    {
         if(i <= 4)
              n[i] = 0;
         else
         {
              n[i] = aux[j] - 48;   
              j--;
         }
    }    
    
    Sum_Bin(n);
    return 0;
}
