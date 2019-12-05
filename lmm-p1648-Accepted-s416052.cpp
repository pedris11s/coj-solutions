#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> par;

const int INF = 1 << 30;
const int MAXN = 1000;

const int DX[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int DY[] = {0, 1, 1, 1, 0, -1, -1, -1};

int F, C, x1, y1, x2, y2;
int costo[MAXN][MAXN];
char M[MAXN][MAXN];
queue <par> cola;

void bfs()
{
    for (int i = 1; i <= F; i++)
        fill (costo[i] + 1, costo[i] + C + 1, INF);

    costo[x1][y1] = 0;
    cola.push(par(x1,y1));
    while(!cola.empty())
    {
        int f = cola.front().first;
        int c = cola.front().second;
        cola.pop();
        for(int i = 0; i < 8; i++)
        {
            int nf = DX[i] + f;
            int nc = DY[i] + c;
            int newc = costo[f][c];

            if(nf > F || nf > C || nf < 1 || nc < 1)
                continue;

            if(M[f][c] - '0' != i)
                newc += 1;

            if(costo[nf][nc] > newc)
            {
                costo[nf][nc] = newc;
                cola.push(par(nf, nc));
            }
        }
    }
}

int main()
{
    scanf ("%d %d\n", &F, &C);
    for(int i = 1; i <= F; i++)
        scanf("%s\n", M[i]+1);

    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
        bfs();
        printf ("%d\n", costo[x2][y2]);
    }
    return 0;
}
