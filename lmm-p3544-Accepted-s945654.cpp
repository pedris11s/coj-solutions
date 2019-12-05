#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int, int> par;

const int MAXN = 1007;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int F, C;
int costo[MAXN][MAXN];
bool mk[MAXN][MAXN];
char M[MAXN][MAXN];
int X, Y;

bool valido(int x, int y)
{
    if(!mk[x][y] && M[x][y] == '.' && x >= 1 && y >= 1 && x <= F && y <= C)
        return true;
    return false;
}

int bfs(int xx, int yy)
{
    for(int i = 1; i <= F; i++)
        for(int j = 1; j <= C; j++)
            costo[i][j] = mk[i][j] = 0;

    queue <par> cola;
    cola.push(par(xx, yy));
    mk[xx][yy] = true;

    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        for(int i = 0; i < 4; i++)
        {
            int x = actual.first + dx[i];
            int y = actual.second + dy[i];

            if(valido(x, y))
            {
                cola.push(par(x, y));
                costo[x][y] = costo[actual.first][actual.second] + 1;
                mk[x][y] = true;
            }

        }
    }
    int ans = -1;
    for(int i = 1; i <= F; i++)
        for(int j = 1; j <= C; j++)
            if(costo[i][j] > ans)
            {
                ans = costo[i][j];
                X = i;
                Y = j;
            }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> C >> F;
        for(int i = 1; i <= F ;i++)
            for(int j = 1; j <= C; j++)
                cin >> M[i][j];

        int sol = -1; bool flag = false;
        for(int i = 1; i <= F ;i++)
            for(int j = 1; j <= C; j++)
                if(M[i][j] == '.' && !flag)
                    sol = bfs(i, j), flag = true;

        sol = bfs(X, Y);

        cout << "Maximum rope length is " << sol << ".\n";
    }

    return 0;
}
