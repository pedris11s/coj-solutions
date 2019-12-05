//by pter

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 2013;

char a[MAXN];
bool pal[MAXN][MAXN];
int F[MAXN];
int G[MAXN];

int main()
{
	cin >> &a[1];
	int size = strlen(&a[1]);
	
	//precalculo para los palindromes
	for(int i = 1; i <= size; i++)
		pal[i][i] = true;
	
	for(int i = 1; i < size; i++)
		pal[i][i + 1] = (a[i] == a[i + 1]);
	
	for(int l = 3; l <= size; l++)
		for(int pi = 1; pi <= size - l + 1; pi++)
			if(a[pi] == a[pi + l - 1])	
				pal[pi][pi + l - 1] = pal[pi + 1][pi + l - 2];
	
	//precalculo para G[]
	for(int i = size; i >= 2; i--)
		for(int j = i; j <= size; j++)
			if(pal[i][j])
				G[i]++;
	
	//precalculo para F[]
	F[1] = 1;
	for(int i = 2; i <= size; i++)
	{
		int cont  = 0;
		for(int j = i; j >= 1; j--)
			if(pal[j][i])
				cont++;
				
		F[i] = F[i - 1] + cont;
	}
	//construyendo la solucion
	long long sol = 0;
	for(int i = 2; i <= size; i++)
		sol += (F[i - 1] * G[i]);
		
	cout << sol << endl;
	return 0;
}
