#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>

using namespace std;

const int MAXF = 12, MAXC = 10;

typedef pair <int, int> par;

char M[MAXF][MAXC];
bool mk[MAXF][MAXC];

int MAT[MAXF][MAXC];

bool flag;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int f, int c)
{
    for(int i = 0; i < MAXF; i++)
        for(int j = 0; j < MAXC; j++)
            mk[i][j] = false;

    queue <par> cola;
    cola.push(par(f, c));
    mk[f][c] = true;
    int cont = 0;
    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();
        cont++;
        if(cont == 3)
            return true;
        for(int i = 0; i < 4; i++)
        {
            int nf = dx[i] + actual.first;
            int nc = dy[i] + actual.second;
            if(nf < MAXF && nc < MAXC && nf > -1 && nc > -1 && !mk[nf][nc] && M[actual.first][actual.second] == M[nf][nc])
            {
                cola.push(par(nf, nc));
                mk[nf][nc] = true;
            }

        }
    }

    return false;
}


void bfs(int f, int c)
{
    for(int i = 0; i < MAXF; i++)
        for(int j = 0; j < MAXC; j++)
            mk[i][j] = false;

    queue <par> cola;
    cola.push(par(f, c));
    mk[f][c] = true;
    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + actual.first;
            int ny = dy[i] + actual.second;
            if(nx < MAXF && ny < MAXC && nx > -1 && ny > -1 && !mk[nx][ny] && M[actual.first][actual.second] == M[nx][ny])
            {
                mk[nx][ny] = true;
                cola.push(par(nx, ny));
            }
        }
    }
}

void Actualiza1()
{
    for(int i = 0; i < MAXF; i++)
        for(int j = 0; j < MAXC; j++)
            if(mk[i][j])
                M[i][j] = ' ';

    for(int j = MAXC - 1; j > -1; j--)
        for(int i = MAXF - 1; i > -1; i--)
            if(M[i][j] == ' ')
                for(int k = i - 1; k > -1; k--)
                    if(M[k][j] != ' ')
                    {
                        swap(M[i][j], M[k][j]);
                        break;
                    }
}
void Actualiza2()
{
    flag = false; int col;
    for(int j = 0; j < MAXC; j++)
    {
        if(M[MAXF - 1][j] == ' ')
        {
            col = j;
            flag = true;
        }
        if(flag)
            break;
    }

    if(flag)
    {
        for(int i = 0; i < MAXF; i++)
            for(int j = 0; j < MAXC; j++)
                mk[i][j] = false;

        int col2 = col;
        while(M[MAXF - 1][col2] == ' ')
            col2++;

        if(col2 == MAXC)
            return;

        for(int i = 0; i < MAXF; i++)
            for(int j = col; j < col2; j++)
                mk[i][j] = true;

        for(int i = 0; i < MAXF; i++)
            for(int j = col; j < MAXC; j++)
                if(mk[i][j])
                    for(int k = j + 1; k < MAXC; k++)
                        if(!mk[i][k])
                        {
                            swap(M[i][j], M[i][k]);
                            break;
                        }
    }
    flag = false;
    for(int j = 0; j < MAXC; j++)
        if(M[MAXF - 1][j] == ' ')
        {
            col = j;
            flag = true;
        }
    if(flag)
        Actualiza2();
}

int main()
{
    //freopen(".in", "r", stdin);

    int t;
    while(cin >> t)
    {
        if(t == 0)
            break;
        for(int i = 0; i < MAXF; i++)
            scanf("%s", M[i]);

        for(int i = 0; i < t; i++)
        {
            char c;int f;
            cin >> c >> f;

            int ff = MAXF - f, cc = c - 'a';
            if(check(ff, cc))
            {
                //cout << "CORRECTO\n";
                bfs(ff, cc);
                Actualiza1();
                Actualiza2();
            }
            //else
            //    cout <<"NO CORRECTO\n";
        }
        int sol = 0;
        for(int i = 0; i < MAXF; i++)
            for(int j = 0; j < MAXC; j++)
                if(M[i][j] != ' ')
                    sol++;
        cout << sol << endl;;
    }

    return 0;
}
