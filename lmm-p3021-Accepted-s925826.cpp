#include <bits/stdc++.h>

using namespace std;

const int MAXN = 103;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

typedef pair <int, int> par;

int N;
char M[MAXN][MAXN];

void bfs1()
{
    queue <par> cola;
    cola.push(par(0, 0));
    M[0][0] = 'X';

    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = actual.first + dx[i];
            int ny = actual.second + dy[i];

            if(nx < MAXN && nx > -1 && ny < MAXN && ny > -1 && M[nx][ny] == 'H')
            {
                cola.push(par(nx, ny));
                M[nx][ny] = 'X';
            }
        }
    }
}

int bfs2(int x, int y)
{
    queue <par> cola;
    cola.push(par(x, y));
    M[x][y] = 'H';

    int sol = 0;
    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        int a = actual.first;
        int b = actual.second;

        if(M[a - 1][b] == 'X')sol++;
        if(M[a][b + 1] == 'X')sol++;
        if(M[a + 1][b] == 'X')sol++;
        if(M[a][b - 1] == 'X')sol++;

        for(int i = 0; i < 4; i++)
        {
            int nx = actual.first + dx[i];
            int ny = actual.second + dy[i];

            if(nx < MAXN && nx > 0 && ny < MAXN - 1 && ny > 0 && M[nx][ny] == 'B')
            {
                cola.push(par(nx, ny));
                M[nx][ny] = 'H';
            }

        }
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 0; i < MAXN ; i++)
        for(int j = 0; j < MAXN; j++)
            M[i][j] = 'H';

    cin >> N;

    int X, Y;
    for(int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        X = x, Y = y;
        M[x][y] = 'B';
    }

    bfs1();
    /*for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            cout << M[i][j];
        cout << endl;
    }
    cout << endl;*/
    int sol = bfs2(X, Y);
    cout << sol << "\n";

    return 0;
}
