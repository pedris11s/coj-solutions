#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXH = 3245;
const int MAXW = 4325;

const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

typedef pair <int, int> pii;

#define MKP(a, b) make_pair((a), (b))

int w, h;
char M[MAXH][MAXW];
queue <pii> cola;

bool valido(int i, int j)
{
	return i < h && j < w && i >= 0 && j >= 0 && M[i][j] == '0';
}

void BFS(int i, int j)
{
	cola.push(MKP(i, j));
	M[i][j] = '1';
	
	while( !cola.empty() )
	{
		pii actual = cola.front();
		cola.pop();
		
		for(int k = 0; k < 4; k++)
		{
			pii coo = MKP(actual.first + DX[k], actual.second + DY[k]);
			
			if(valido(coo.first, coo.second))
			{
				cola.push(coo);
				M[coo.first][coo.second] = '1';
			}
		}
	}
}

int main()
{
	scanf("%d%d", &w, &h);
	
	for(int i = 0; i < h; i++)
		scanf("%s", M[i]);
		
	/*cout << "MATRIZ\n";
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
			cout << M[i][j];
		cout << endl;
	}*/

	int bugs = 0;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			if(M[i][j] == '0')
			{
				BFS(i, j);
				bugs++;
			}
	printf("%d\n", bugs);
	return 0;
}
