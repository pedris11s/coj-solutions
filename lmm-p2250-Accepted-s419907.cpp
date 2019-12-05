#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 1000006;

int N, M, sol;
char A[MAXN + 1],B[MAXN + 1];

void preKMP(int *F)
{
    int j;
	for(int i = 1; i < M; i++)
	{
		j = F[i - 1];
		while(j > -1 && B[j + 1] != B[i])
            j = F[j];

		if(B[j + 1] == B[i])
            F[i] = j + 1;
	}
}

void KMP(){

	int F[MAXN + 1];
	fill(F,F + M, -1);

	preKMP(F);
	int j = -1;
	for(int i = 0; i  < N; ++i)
	{
		while(j >-1 && B[j + 1] != A[i])
            j = F[j];
		if(B[j + 1] == A[i])
            j++;
		if(j == (M-1))
            sol++;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int k = 1;
	while(t--)
	{
		scanf("%s%s", A, B);
		N = strlen(A);
		M = strlen(B);

		sol = 0;
		KMP();
		printf("Case %d: %d\n", k++, sol);
	}
	return 0;
}
