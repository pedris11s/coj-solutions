//by pter

/*
5 4
1 3 1
1 2 2
2 3 3
2 4 1
*/

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

const int MAX = 1005;

int N, r;
int M[MAX][MAX];
bool mk[MAX];
huge C[MAX];

huge Prim()
{
	for(int i = 1; i <= N; i++)
		C[i] = -1;
	
	C[1] = 0;
	huge SOL = 0;
	int cantmk = 0;
	for(int i = 1; i <= N; i++)
	{
		int nodo;
		huge max = -1;
		for(int j = 1; j <= N; j++)
			if( !mk[j] && C[j] > max)
			{
				max = C[j];
				nodo = j;
			}
		if (max == -1)
			break;
		//cout << nodo << ' ';
		SOL += max;
		mk[nodo] = true;
		cantmk++;
		for(int j = 1; j <= N; j++)
			if( !mk[j] && M[nodo][j] > 0 && M[nodo][j] > C[j] )
				C[j] = M[nodo][j];
	}
	if(cantmk == N)
		return SOL;
	
	return -1;
}

int main()
{
	
	cin >> N >> r;
	for(int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(c > M[a][b])
			M[a][b] = M[b][a] = c;
	}
	cout << Prim() << endl;	
	return 0;
}
