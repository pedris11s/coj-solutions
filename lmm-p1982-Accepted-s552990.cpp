#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair <int, int> par;

const char p = 'X';
const int MAX = 55;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int F, C;
char M[MAX][MAX];
vector <par> V1, V2;

bool is_coast(int i, int j)
{
    if(M[i - 1][j] == p && M[i][j + 1] == p && M[i + 1][j] == p && M[i][j - 1] == p)
        return false;
    else
        return true;
}


void dfs(int i, int j, char x)
{
    M[i][j] = x;
    if(is_coast(i, j))
    {
        if(x == '1')
            V1.push_back(par(i, j));
        else
            V2.push_back(par(i, j));
    }

    for(int k = 0; k < 4; k++)
    {
        int ii = i + dx[k];
        int jj = j + dy[k];
        if(M[ii][jj] == 'X' && ii <= F && jj <= C && ii >= 1 && jj >= 1)
            dfs(ii, jj, x);
    }
}


int dist(par A, par B)
{
    return abs(A.first - B.first) + abs(A.second - B.second);
}

int main()
{
    scanf("%d%d", &F, &C);
    for(int i = 1; i <= F; i++)
        scanf("%s", M[i] + 1);

    char x = '1';
    for(int i = 1; i <= F; i++)
        for(int j = 1; j <= C; j++)
            if(M[i][j] == 'X')
            {
                dfs(i, j, x);
                x++;
            }

    int sol = (1 << 20);
    par a, b;
    for(int i = 0; i < V1.size(); i++)
        for(int j = 0; j < V2.size(); j++)
        {
            int d = dist(V1[i], V2[j]);
            if(d < sol)
            {
                sol = d;
                a = V1[i];
                b = V2[j];
            }
        }

    cout << sol - 1 << endl;
    /*cout << a.first << ' ' << a.second << endl;
    cout << b.first << ' ' << b.second << endl;*/



    return 0;
}


