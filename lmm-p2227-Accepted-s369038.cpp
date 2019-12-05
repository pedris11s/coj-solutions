//by pter

#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 15;

int N;
char M[MAXN][MAXN];
int x, y;
int SOL = 200;

const int DX[] = {0, 1};
const int DY[] = {1, 0};

bool valido(int i, int j)
{
	return i < x && j < y;
}

void Camino(int i, int j, int costo)
{
	if(costo >= SOL)
		return;
		
	if(i == x - 1 && j == y - 1)
	{	
		if(costo < SOL)
			SOL = costo;
		return;
	}	
	for(int k = 0; k < 2; k++)
	{
		int ii = i + DX[k];
		int jj = j + DY[k];
		if(valido(ii, jj))
		{
			if(M[ii][jj] > M[i][j])
				Camino(ii, jj, costo + M[ii][jj] - M[i][j]);
			else
				Camino(ii, jj, costo);
		}
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		scanf("%s", M[i]);
		
	cin >> x >> y;
	
	Camino(0, 0, 0);
	cout << SOL << endl;
	
	return 0;
}
