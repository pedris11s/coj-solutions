#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> par;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int MAXN = 100;

int N, costo[MAXN][MAXN];
char M[MAXN][MAXN];
par ini, fin;

bool valido(int x, int y)
{
    if(M[x][y] != '*' && x <= N && x >= 1 && y <= N && y >= 1)
        return true;
    return false;
}

int bfs()
{
    queue <par> cola;
    cola.push(ini);
    M[ini.first][ini.second] = '*';

    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        if(actual == fin)
            return costo[actual.first][actual.second];

        for(int i = 0; i < 4; i++)
        {
            int x = actual.first + dx[i];
            int y = actual.second + dy[i];

            if(valido(x, y))
            {
                cola.push(par(x, y));
                costo[x][y] = costo[actual.first][actual.second] + 1;
                M[x][y] = '*';
            }
        }
    }
    return -1;

}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            cin >> M[i][j];
            if(M[i][j] == 'm')
                ini = par(i, j);
            else if(M[i][j] == '#')
                fin = par(i, j);
        }

    cout << bfs() << endl;
/*
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            cout << costo[i][j];
            cout << endl;
            }*/
    return 0;
}
