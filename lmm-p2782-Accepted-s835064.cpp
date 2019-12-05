#include <bits/stdc++.h>

using namespace std;

const int INF = (1 << 10);
const int MAXN = 15;

typedef pair <int, int> par;

int N;
char M[MAXN][MAXN];
int costo[MAXN][MAXN];
bool mk[MAXN][MAXN];

int DX[4] = {-1, 0, 1, 0};
int DY[4] = {0, 1, 0, -1};

bool valido(par pos)
{
    if(pos.first <= N && pos.second <= N && pos.first >= 1 && pos.second >= 1 && M[pos.first][pos.second] != '*')
        return true;
    return false;
}

void bfs(int f, int c)
{
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            costo[i][j] = INF;

    queue <pair <int, int> > cola;
    cola.push(par(f, c));
    mk[f][c] = true;
    costo[f][c] = 0;

    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        for(int i = 0; i < 4; i++)
        {
            par nn = par(actual.first + DX[i], actual.second + DY[i]);
            if(valido(nn) && !mk[nn.first][nn.second] && costo[actual.first][actual.second] + 1 < costo[nn.first][nn.second])
            {
                mk[nn.first][nn.second] = true;
                cola.push(nn);
                costo[nn.first][nn.second] = costo[actual.first][actual.second] + 1;
            }
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> M[i][j];

    par INI, FIN;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(M[i][j] == 'm')
                INI = par(i, j);
            else if(M[i][j] == '#')
                FIN = par(i, j);

    bfs(INI.first, INI.second);
    if(costo[FIN.first][FIN.second] == INF)
        cout << "-1\n";
    else
        cout << costo[FIN.first][FIN.second] << endl;



    return 0;
}
