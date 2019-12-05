#include <cstdio>
#include <iostream>
#include <queue>
#include  <cstring>

using namespace std;

typedef pair<int, int> par;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int R, C, CN;
par G[20];

int Dist[21][21];
char M[21][21];
int costo[21][21];
bool mk[21][21];


int dp[1 << 16][20];
bool calc[1 << 16][20];

bool ok(par a)
{
    return a.first < R && a.second < C && a.first >= 0 && a.second >= 0;
}

int bfs(par ini)
{
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            mk[i][j] = costo[i][j] = 0;

    queue <par> cola;

    cola.push(ini);
    mk[ini.first][ini.second] = 1;

    while(!cola.empty()){
        par CNo = cola.front();
        cola.pop();

        for(int i = 0; i < 8; i++){
            par nn = par(CNo.first + dx[i], CNo.second + dy[i]);
            if(ok(nn) && !mk[nn.first][nn.second]){
                mk[nn.first][nn.second] = 1;
                cola.push(nn);
                costo[nn.first][nn.second] = costo[CNo.first][CNo.second] + 1;
            }
        }
    }
}


int solve(int S, int j)
{
    if(S == 1)
        return 0;

    if(!calc[S][j]){

        int ss = S - (1 << j);
        int sol = (1 << 30);

        for(int i = 0; i < CN; i++){
            if(ss & (1 << i)){
                sol = min(sol, solve(ss, i) + Dist[i][j]);
            }
        }
        calc[S][j] = true;
        dp[S][j] = sol;
    }
    return dp[S][j];
}


int main()
{
    int cas;
    cin >> cas;
    int casos = 1;
    while(cas--){
        cin >> R >> C;
        for(int i = 0; i < R; i++)
            cin >> M[i];

        CN = 1;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(M[i][j] == 'x')
                    G[0] = par(i , j);
                else if(M[i][j] == 'g')
                    G[CN++] = par(i, j);

        for(int i = 0; i < CN; i++){
            bfs(G[i]);
            for(int j = i + 1; j < CN; j++)
                Dist[i][j] = Dist[j][i] = costo[G[j].first][G[j].second];
        }

        memset(calc, 0, sizeof calc);
        int sol = (1 << 30);
        for(int i = 0; i < CN; i++){
            sol = min(sol, solve((1 << CN) - 1, i) + Dist[i][0]);
        }

        cout <<"Case " << casos << ": " << sol << endl;
        casos++;
    }
    return 0;
}
