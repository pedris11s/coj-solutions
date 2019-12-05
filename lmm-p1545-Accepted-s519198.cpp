#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct trio{
    int x, y, v;
    trio(int a, int b, int c)
    {
        x = a, y = b, v = c;
    }
};


const int MAXN = 150;

const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};


int N;
int M[MAXN][MAXN], freq[MAXN];

bool valido(trio A)
{
    return A.x <= N && A.y <= N && A.x >= 1 && A.y >= 1 && M[A.x][A.y] != -1;
}

void bfs(int i, int j)
{
    queue <trio> cola;
    cola.push(trio(i, j, M[i][j]));

    M[i][j] = -1;
    while(!cola.empty())
    {
        trio actual = cola.front();
        cola.pop();

        for(int k = 0; k < 4; k++)
        {
            trio coo = trio(actual.x + DX[k], actual.y + DY[k], 0);
            coo.v = M[coo.x][coo.y];

            if(valido(coo) && (actual.v == M[coo.x][coo.y]))
            {

                cola.push(coo);
                M[coo.x][coo.y] = -1;
            }
        }
    }
}

string sol()
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(M[i][j] != -1)
            {
                if(freq[M[i][j]] > 0)
                    return "wrong\n";
                else
                {
                    freq[M[i][j]]++;
                    bfs(i, j);
                }
            }
    return "good\n";
}

int main()
{
    while(cin >> N)
    {
        if(N == 0)
            break;

        fill(freq, freq + N + 1, 0);
        for(int i = 0; i <= N; i++)
            for(int j = 0; j <= N; j++)
                M[i][j] = 0;

        for(int i = 1; i <= N - 1; i++)
            for(int j = 0; j < N; j++)
            {
                int a, b;
                cin >> a >> b;
                M[a][b] = i;
            }
        cout << sol();
    }

    return 0;
}
