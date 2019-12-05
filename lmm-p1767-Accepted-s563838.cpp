#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int MAXN = 2005;

int F, C;
LL M[MAXN][MAXN];
LL ta[MAXN][MAXN];
LL dd[MAXN][MAXN];
LL di[MAXN][MAXN];

inline bool ok(int i, int j)
{
	return (i > 0) && (j > 0) && (i <= F) && (j <= C);
}

int main()
{
    cin >> F >> C;
    for(int i = 1; i <= F; i++)
        for(int j = 1; j <= C; j++)
            cin >> M[i][j];

    //diagonal izquierda
    for(int i = 1; i <= F; i++)
        for(int j = 1; j <= C; j++)
            di[i][j] = M[i][j] + di[i - 1][j - 1];

    //diagonal derecha
    for(int i = 1; i <= F; i++)
        for(int j = 1; j <= C; j++)
            dd[i][j] = M[i][j] + dd[i - 1][j + 1];

    //fila uno
    for(int j = 1; j <= C; j++)
        ta[1][j] = M[1][j];


    //fila dos
    for(int j = 1; j <= C; j++)
        ta[2][j] = M[2][j] + M[1][j - 1] + M[1][j] + M[1][j + 1];




    //fila tres pa' lante
    for(int i = 3; i <= F; i++)
        for(int j = 1; j <= C; j++)
            ta[i][j] = M[i][j] + ta[i - 1][j] + di[i - 1][j - 1] + dd[i - 1][j + 1];
            //ta[i][j] = M[i][j] + M[i - 1][j] + ta[i - 1][j - 1] + ta[i - 1][j + 1] - ta[i - 2][j];





    /*for(int i = 1; i <= F; i++)
    {
        for(int j = 1; j <= C; j++)
            cout << ta[i][j] << '\t';
        cout << endl;
     }*/

    int Q;
    cin >> Q;
    while(Q--)
    {
        int x, y, r;
        cin >> x >> y >> r;
        x++;y++;

        LL sol = ta[x + r][y];
        /*if(r == 0)
        {
            sol = M[x][y];
            continue;
        }-*/

        if(ok(x - 1, y + r) && ok(x - 1, y + r))
            sol -= ta[x - 1][y + r] + ta[x - 1][y - r];

        if(ok(x - r - 1, y))
            sol += ta[x - r - 1][y];
        if(ok(x - 1, y - r - 1))
            sol -= di[x - 1][y - r - 1];
        if(ok(x - 1, y + r + 1))
            sol -= dd[x - 1][y + r + 1];

        if(r == 0)
            sol = M[x][y];

        cout << sol << endl;
    }


    return 0;
}
