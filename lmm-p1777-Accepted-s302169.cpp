#include <cstdio>

const int MAXN = 10005;

int freq[MAXN];
int cont;

int main()
{
    int n;
    scanf("%d",&n);
    int ni;
    for(int i = 1; i <= n; i++)
    {     
    	 scanf("%d",&ni);
         freq[ni]++;
    }
    for(int i = 1; i <= n; i++)
         if(freq[i] == 0)
              cont++; 
              
    printf("%d\n",cont);
    return 0;
}