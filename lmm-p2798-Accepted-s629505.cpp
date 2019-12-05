#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

LL TP[100][100];

void pascal_triangle()
{
    for(int i = 0; i <= 73; i++)
        TP[i][0] = TP[i][i] = 1;

    for(int i = 1; i <= 73; i++)
        for(int j = 1; j < i; j++)
            TP[i][j] = TP[i - 1][j - 1] + TP[i - 1][j];
}

int main()
{
    pascal_triangle();
    /*for(int i = 0; i <= 20; i++)
    {
        for(int j = 0; j <= 20; j++)
            if(TP[i][j] == 0)
                continue;
            else
                cout << TP[i][j] << ' ';
        cout << endl;
    }*/
    int t;
    cin >> t;
    while(t--)
    {
        int x, n;
        cin >> x >> n;
        cout << x << ' ' << TP[n + 9][n] << endl;
    }

    return 0;
}