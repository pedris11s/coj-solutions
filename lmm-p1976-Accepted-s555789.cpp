#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1005;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct tri{
	int cost, f, c;

	tri (int a = 0, int b = 0, int d = 0)
	{
		cost = a;
		f = b;
		c = d;
	}

	bool operator < (const tri &p) const
	{
		return cost > p.cost;
	}
};

priority_queue <tri> cola;
int N, X, Y, costo[MAXN][MAXN], M[MAXN][MAXN];

int main()
{
	cin >> N >> X >> Y;
	for(int i = 0; i < N; i++)
	{
	    int a, b;
        cin >> b >> a;
		M[a + 1][b + 1] = true;
	}

    memset (costo, 29, sizeof (costo));

	for(int i = 0; i <= 1003; i++)
	    M[i][0] = M[0][i] = M[1003][i] = M[i][1003] = -1;

	costo[Y + 1][X + 1] = 0;
	cola.push (tri (0, Y + 1, X + 1));

	while(!cola.empty())
	{
		int x = cola.top().f;
		int y = cola.top().c;
		int cost = cola.top().cost;
		cola.pop();

		if (x == 1 || y == 1)
		{
			cout << costo[x][y] << endl;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if(M[nx][ny] != -1 && costo[nx][ny] > cost + M[nx][ny])
			{
				costo[nx][ny] = cost + M[nx][ny];
				cola.push (tri (costo[nx][ny], nx, ny));
			}
		}
	}
}
