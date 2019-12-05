//by pter
//algorithm: RMQ

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 50005;

struct par{
    int min, max;
}R[MAXN][20];

int A[MAXN];

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
    //cout << exp(50000) << endl;

    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

	for(int i = 1; i <= n; i++)
        R[i][0].min = R[i][0].max = A[i];

	int MAXE = exp(n);
    for(int e = 1; e <= MAXE; e++)
    {
        int aux = n - (1 << e) + 1;
        for(int i = 1; i <= aux; i++)
        {
            R[i][e].min = min(R[i][e - 1].min, R[i + (1 << (e - 1))][e - 1].min);
            R[i][e].max = max(R[i][e - 1].max, R[i + (1 << (e - 1))][e - 1].max);
        }
    }
    for(int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b)
			swap(a, b);

		int e = exp(b - a + 1);
		int m = min(R[a][e].min, R[b - (1 << e) + 1][e].min);
		int M = max(R[a][e].max, R[b - (1 << e) + 1][e].max);
		printf("%d\n", M - m);
    }
    return 0;
}
