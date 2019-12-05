//by pter

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>//funcion min() q devuelve el menor de dos numeros;

using namespace std;

const int MAX = 15;

int M[MAX][MAX];
int TA[MAX][MAX];

inline int sum (int i, int j, int ii, int jj)
{
    int sum = TA[ii][jj] - TA[i - 1][jj] - TA[ii][j - 1] + TA[i -1][j - 1];

    return sum;
}

inline int area(int i, int j, int ii, int jj)
{
    int area = (ii - i + 1) * (jj - j + 1);
    return area;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                char c;
                cin >> c;
                M[i][j] = (c != '.');
            }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                TA[i][j] = M[i][j] + TA[i - 1][j] + TA[i][j - 1] - TA[i - 1][j - 1];

        int sol = 0;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                for(int k = 1; k <= min(n - i + 1, n - j + 1); k++)
                    if( sum(i, j, i + k - 1, j + k - 1) == 0 && area(i, j, i + k - 1, j + k - 1) > sol )
                        sol = area(i, j, i + k - 1, j + k - 1);

        cout << (int)sqrt(sol) << "\n";
    }

    return 0;
}
