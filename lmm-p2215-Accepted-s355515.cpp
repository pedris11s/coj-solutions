//by pter

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1005;

#define x first
#define y second
#define MKP(a, b) make_pair((a), (b))

const int DX[] = {-2, -3, 0, 0, 2, 3, 0, 0};
const int DY[] = {0, 0, 2, 3, 0, 0, -2, -3};

int n;
bool mk[MAXN][MAXN];
int costo[MAXN][MAXN];
queue <pii> cola;

bool valido(pii a)
{
    return a.x >= 1 && a.y >= 1 && a.x <= n && a.y <= n;
}

int BFS()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            mk[i][j] = false;
            costo[i][j] = 0;
        }
    while( !cola.empty() )
        cola.pop();

    cola.push(MKP(1, 1));
    mk[1][1] = true;

    int cantmk = 1;

    while( !cola.empty() )
    {
        pii actual = cola.front();
        cola.pop();

        for(int i = 0; i < 8; i++)
        {
            pii p = MKP(actual.x + DX[i], actual.y + DY[i]);

            if(valido(p) && !mk[p.x][p.y])
            {
                mk[p.x][p.y] = true;
                cola.push(p);
                cantmk++;
                costo[p.x][p.y] = costo[actual.x][actual.y] + 1;
            }
            if(cantmk == n * n)
                return costo[p.x][p.y];
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int sol = BFS();
        cout << sol << endl;
    }
    return 0;
}
