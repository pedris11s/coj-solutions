#include <cstdio>
#include <algorithm>

const int RANG =  1000;
using namespace std;

int t, n, sol, N[RANG];

int Burble (int start, int end)
{
	sol = 0;
	for (int i = start; i < end; i++) 
	{
		if (N[i] > N[i + 1]) 
		{
			swap (N[i], N[i + 1]);
			sol++;
		}
		if (i == end - 1) 
		{
			i = start - 1;
			end--;
		}
	}
	return sol;
}

int main() 
{
	scanf ("%d", &t);
	
	for (int i = 1; i <= t; i++) 
	{
		scanf ("%d", &n);
		for (int j = 1; j <= n; j++)
			scanf ("%d", &N[j]);
			
		printf ("Optimal train swapping takes %d swaps.\n", Burble (1, n));
	}

	return 0;
}
