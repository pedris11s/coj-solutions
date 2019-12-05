#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 1001;

#define p '+'

char M[MAX][MAX];

bool is_coast(int i, int j)
{
    if(M[i - 1][j] == p && M[i][j + 1] == p && M[i + 1][j] == p && M[i][j - 1] == p)
        return false;
    else
        return true;
}

int main()
{
    int n,m;
    int coast = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> M[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(M[i][j] == p && is_coast(i,j))
                coast++;

    cout << coast << endl;

    return 0;
}
