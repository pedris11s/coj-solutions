#include <bits/stdc++.h>

using namespace std;

const int MAXN = 507;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

typedef pair <int, int> par;

int R, C, M[MAXN][MAXN];
int mk[MAXN][MAXN];

bool bfs(int k)
{
    if(k >= M[1][1])return false;

    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            mk[i][j] = -1;

    queue <par> cola;

    cola.push(par(1, 1));
    mk[1][1] = k;

    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        if(actual == par(R, C))
            return true;

        for(int i = 0; i < 4; i++)
        {
            int nx = actual.first + dx[i];
            int ny = actual.second + dy[i];

            if(nx > R || ny > C || nx < 1 || ny < 1)continue;
            if(mk[nx][ny] != -1)continue;

            if(mk[actual.first][actual.second] + 1 < M[nx][ny])
            {
                cola.push(par(nx, ny));
                mk[nx][ny] = mk[actual.first][actual.second] + 1;
            }
        }
    }
    return false;
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);

    scanf("%d%d", &R, &C);
    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            scanf("%d", &M[i][j]);

    int ini = 0, fin = M[1][1] - 1, sol = -1;
    while(fin - ini >= 3)
    {
        int mit = (ini + fin) / 2;
        if(bfs(mit))
            ini = mit + 1;
        else
            fin = mit - 1;
    }
    while(bfs(ini))ini++;
    printf("%d\n", ini - 1);
/*
3 2
1000000 1000000
1000000 1000000
1000000 314

3 3
2 3 4
3 4 5
4 5 6


*/
    //cout << sol << "\n";

    return 0;
}
