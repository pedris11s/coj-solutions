#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 30;

int n, s;
int M[MAXN][MAXN];

void rellena()
{
    int cont = s;
    for(int f = 1; f <= n; f++)
        for(int c = 1; c <= f; c++)
        {
            M[c][f] = cont;
            if(cont == 9)
                cont = 1;
            else
                cont++;
        }
}

int main()
{
    cin >> n >> s;
    rellena();

    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << M[i][j] << ' ';
        cout << endl;
    }*/

    for(int f = 1; f <= n; f++)
    {
        for(int c = 1; c <= n; c++)
        {
            if(M[f][c] != 0 && c < n)
                cout << M[f][c] << ' ';
            else if(M[f][c] != 0 && c == n)
                cout << M[f][c];
            else
                cout << "  ";
        }
        if(f < n)
            cout << endl;
    }
    return 0;
}
