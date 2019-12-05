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

const int MAX = 1005;

int M[MAX][MAX];
int TA[MAX][MAX];

int sum (int i, int j, int ii, int jj)
{
    int sum = TA[ii][jj] - TA[i - 1][jj] - TA[ii][j - 1] + TA[i -1][j - 1];

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R, C, Q;
    cin >> R >> C >> Q;

    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            cin >> M[i][j];

    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++){
            TA[i][j] = TA[i - 1][j] + TA[i][j - 1] - TA[i - 1][j - 1];
            if(M[i][j] < 0)
                TA[i][j] += 0;
            else
                TA[i][j] += M[i][j];
        }

    while(Q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum(x1, y1, x2, y2) << "\n";
    }


    return 0;
}
