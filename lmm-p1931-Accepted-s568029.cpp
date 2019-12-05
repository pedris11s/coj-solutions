#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef pair <int, int> par;

const int MAXN = 107;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};


int M[MAXN][MAXN];
int costo[MAXN][MAXN];
map <int, par> P;

bool is_prime(int n)
{
    if(n == 1)return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;

    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

void build_matriz()
{
    //centinelas
    for(int i = 0; i < MAXN; i++)
        M[0][i] = M[i][0] = M[i][MAXN - 1] = M[MAXN - 1][i] = -1;

    int i = 1, j = 1, Num = (MAXN - 2) * (MAXN - 2);
    int d = 0;
    while(true)
    {
        M[i][j] = Num--;

        P[M[i][j]] = par(i, j);
        if(is_prime(M[i][j]))
            M[i][j] = -1;

        if(Num == 0)
            break;

        int ii = i + dx[d];
        int jj = j + dy[d];
        if(M[ii][jj] == 0)
            i = ii, j = jj;
        else
        {
            d = (d + 1) % 4;
            i += dx[d];
            j += dy[d];
        }

    }

}

int bfs(par ini, par fin)
{
    queue <par> cola;
    memset(costo, 0, sizeof costo);

    cola.push(ini);
    costo[ini.first][ini.second] = 1;

    while(!cola.empty())
    {
        int f = cola.front().first;
        int c = cola.front().second;
        cola.pop();

        if(f == fin.first && c == fin.second)
            return costo[f][c] - 1;

        for(int k = 0; k < 4; k++)
        {
            int nf = f + dx[k];
            int nc = c + dy[k];
            if(M[nf][nc] != -1 && costo[nf][nc] == 0)
            {
                cola.push(par(nf, nc));
                costo[nf][nc] = costo[f][c] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    build_matriz();

    int n1, n2;
    int cas = 1;
    while(cin >> n1 >> n2)
    {
        //cout << P[n1].first << ' ' << P[n1].second << endl;
        int sol = bfs(P[n1], P[n2]);
        cout << "Case " << cas << ": ";
        if(sol == -1)
            cout << "impossible\n";
        else
            cout << sol << "\n";
        cas++;
    }

    /*for(int i = 0; i < MAXN; i++)
    {
        for(int j = 0; j < MAXN; j++)
            cout << M[i][j] << '\t';
        cout << endl;
    }*/


    return 0;
}
