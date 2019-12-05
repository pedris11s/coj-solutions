#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100001;

const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

typedef pair <int, int> pii;

int F, C, szisl;
vector <char> M[MAXN];
queue <pii> cola;

void bfs(int i, int j)
{
    cola.push(pii(i, j));
    M[i][j] = '0';
    szisl++;
    while(!cola.empty())
    {
        pii actual = cola.front();
        cola.pop();

        for(int k = 0; k < 4; k++)
        {
            pii coo = pii(actual.first + DX[k], actual.second + DY[k]);
            if(coo.first < F && coo.second < C && coo.first > -1 && coo.second > -1 && M[coo.first][coo.second] == '1')
            {
                cola.push(coo);
                M[coo.first][coo.second] = '0';
                szisl++;
            }
        }
    }
}

int main()
{

    scanf("%d%d", &F, &C);
    for(int i = 0; i < F; i++)
    {
        scanf("\n");
        for(int j = 0; j < C; j++)
        {
            char c;
            scanf("%c", &c);
            M[i].push_back(c);
        }
    }
    int ci = 0, maxisl = 0;
    for(int i = 0; i < F; i++)
        for(int j = 0; j < C; j++)
            if(M[i][j] == '1')
            {
                szisl = 0;
                bfs(i, j);
                ci++;
                if(szisl > maxisl)
                    maxisl = szisl;
            }

    cout << ci << ' ' << maxisl << endl;

    return 0;
}
