//by pter

#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 105;

int n;
char M[MAXN][MAXN];
int size;

int DX[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int DY[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool valido(int x, int y)
{
    return x > -1 && y > -1 && x < n && y < n;
}

void DFS(int i, int j)
{
    M[i][j] = 's';
    size++;
    for(int k = 0; k < 8; k++)
    {
        int ii = i + DX[k];
        int jj = j + DY[k];
        if(valido(ii, jj) && M[ii][jj] == 'l')
            DFS(ii, jj);
    }
}

int main()
{

    while(true)
    {
        cin >> n;
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            scanf("%s", M[i]);

        int cont = 0;
        int maxi = 0;
        int mini = 10000;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(M[i][j] == 'l')
                {
                    cont++;
                    size = 0;
                    DFS(i, j);
                    if(size < mini)
                        mini = size;
                    if(size > maxi)
                        maxi = size;
                    //cout << size << endl;
                }
            }
        if(cont == 0)
            mini = 0;

        printf("%d %d %d\n", cont, mini, maxi);

    }
    return 0;
}

