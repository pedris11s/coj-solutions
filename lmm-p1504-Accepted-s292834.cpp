//by pter

#include <cstdio>

const int MAX = 1000001;

int digP(int n)
{
    int digP = 1;
    
    while(n > 0)
    {
         digP *= (n % 10);
         n /= 10;
    }
    return digP;
}

bool A[MAX];
int T[MAX];
int a,b;

int main()
{
    for(int i = 1; i <= MAX; i++)
		if(!(digP(i) & 1))
			A[i] = true;
           
    for(int i = 2; i <= MAX; i++)
		T[i] = T[i - 1] + A[i];
		
	//for(int i = 1; i < 100; i++)   
      //   printf("%d) %d\n",i,T[i]);	 
		
	int k;
    scanf("%d",&k);	
	for(int IND = 0; IND < k; IND++)
    {
        scanf("%d%d", &a, &b);
		int sol = T[b] - T[a - 1];
		printf("%d\n",sol);
	}
    return 0;
}
