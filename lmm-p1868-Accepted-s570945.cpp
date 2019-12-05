#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair <int, int> par;
typedef pair <int, par> trio;

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int R, C, CN;
par G[50];
int Dist[50][50];

char M[50][50];
int costo[50][50];
bool mk[50][50];

int dp[(1 << 16)][50];
bool calc[(1 << 16)][50];

int solve(int S, int j)
{
    if(S == 1)
        return 0;
    if(!calc[S][j])
    {
        int sol = (1 << 30);
        int ss = S - (1 << j);
        for(int x = 0; x < CN; x++)
            if((ss & (1 << x)))
                sol = min(sol, solve(ss, x) + Dist[x][j]);
        dp[S][j] = sol;
        calc[S][j] = true;
    }
    return dp[S][j];
}

void bfs(par ini)
{
    queue <par> cola;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            costo[i][j] = mk[i][j] = 0;

    cola.push(ini);
    mk[ini.first][ini.second] = true;
    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        for(int i = 0; i < 8; i++)
        {
            par coo = par(actual.first + dx[i], actual.second + dy[i]);
            if(coo.first < R && coo.second < C && coo.first > -1 && coo.second > -1 && !mk[coo.first][coo.second])
            {
                cola.push(coo);
                mk[coo.first][coo.second] = true;
                costo[coo.first][coo.second] = costo[actual.first][actual.second] + 1;
            }
        }
    }
}

int main()
{
    //freopen(".in", "r", stdin);

    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++)
    {

        cin >> R >> C;
        CN = 1;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
            {
                cin >> M[i][j];
                if(M[i][j] == 'x')
                    G[0] = par(i, j);
                else if(M[i][j] == 'g')
                    G[CN++] = par(i, j);
            }
        for(int i = 0; i < CN; i++)
        {
            bfs(G[i]);
            for(int j = 0; j < CN; j++)
                Dist[i][j] = Dist[j][i] = costo[G[j].first][G[j].second];
        }

        for(int i = 0; i < (1 << CN) + 2; i++)
            for(int j = 0; j < CN + 2; j++)
                dp[i][j] = calc[i][j] = 0;

        int sol = (1 << 30);
        for(int i = 0; i < CN; i++)
            sol = min(sol, solve((1 << CN) - 1, i) + Dist[i][0]);
        cout << "Case " << cas << ": "<< sol << endl;;
    }
    return 0;
}
