#include <cstdio>
#include <iostream>

/*
3
10 90 -20
-3 -15 100
-3 -30 100

4
0 -2 -7 0
9 2 -6 2
-4 1 -4  1
-1 8 0 -2
*/

using namespace std;

const int MAX = 105;

int M[MAX][MAX];
int TA[MAX][MAX];

int sum (int i, int j, int ii, int jj)
{
    int sum = TA[ii][jj] - TA[i - 1][jj] - TA[ii][j - 1] + TA[i -1][j - 1];

    return sum;
}

int main()
{
    int n;

    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> M[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            TA[i][j] = M[i][j] + TA[i - 1][j] + TA[i][j - 1] - TA[i - 1][j - 1];

    int sol = -127 * 10000;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)
            for (int ii = i ; ii <= n ; ii++)
                for (int jj = j ; jj <= n ; jj++)
                    if (sum(i, j, ii, jj) > sol)
                        sol = sum(i, j, ii, jj);

    cout << sol << '\n';

    return 0;
}
