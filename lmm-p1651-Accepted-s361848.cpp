//by pter
//algorithm: RMQ

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

int A[MAXN];
int R[MAXN][15];//log2(MAXN);

int exp(int n)
{
    int e = 0;
    int p = 1;
    while(p <= n)
    {
        p *= 2;
        e++;
    }
    return --e;
}

int main()
{
    int n;
    scanf("%d", &n);
    //cout << exp(n) << endl;
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

	for(int i = 1; i <= n; i++)
        R[i][0] = A[i];
	
	int MAXE = exp(n);
    for(int e = 1; e <= MAXE; e++)
    {
        int aux = n - (1 << e) + 1;
        for(int i = 1; i <= aux; i++)
            R[i][e] = min(R[i][e - 1], R[i + (1 << (e - 1))][e - 1]);
    }
	int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b)
			swap(a, b);
			
		int e = exp(b - a + 1);
		int sol = min(R[a][e], R[b - (1 << e) + 1][e]);
		printf("%d\n", sol);
    }
    return 0;
}
