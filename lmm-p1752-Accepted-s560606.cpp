#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 2013;

int n, w, l;
int M[MAXN][MAXN];
int TA[MAXN][MAXN];

int sum(int i, int j, int ii, int jj)
{
    return TA[ii][jj] - TA[i - 1][jj] - TA[ii][j - 1] + TA[i - 1][j - 1];
}

int area(int i, int j, int ii, int jj)
{
    return (ii - i + 1) * (jj - j + 1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> w >> l;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                TA[i][j] = 0;

        for(int i = 1; i <= w; i++)
        {
            int x, y;
            cin >> x >> y;
            TA[x][y] = 1;
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                TA[i][j] += TA[i - 1][j] + TA[i][j - 1] - TA[i - 1][j - 1];

        int sol = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                int ini = 1, fin = min(n - i + 1, n - j + 1);
                while (fin - ini > 5){
                    int mit = (ini + fin) >> 1;
                    if (sum(i, j, i + mit - 1, j + mit - 1) <= l)
                        ini = mit;
                    else
                        fin = mit - 1;
                }
                while (ini <= min(n - i + 1, n - j + 1) && sum(i, j, i + ini - 1, j + ini - 1) <= l)
                    ini++;
                if ((ini - 1) * (ini - 1) > sol)
                    sol = (ini - 1) * (ini - 1);
            }

        cout << sol << endl;
    }

    return 0;
}
