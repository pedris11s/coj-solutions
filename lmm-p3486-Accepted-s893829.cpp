/*
9 4 1 | 5 3 2 | 8 6 7
6 5 2 | 7 8 4 | 9 1 3
7 3 8 | 1 9 6 | 2 5 4
------+-------+------
2 1 3 | 6 7 5 | 4 8 9
8 7 9 | 4 1 3 | 5 2 6
4 6 5 | 8 2 9 | 7 3 1
------+-------+------
1 9 4 | 3 5 8 | 6 7 2
5 2 7 | 9 6 1 | 3 4 8
3 8 6 | 2 4 7 | 1 9 5
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

typedef long long LL;

int M[10][10];
bool freq[10];

bool filasycolumnas()
{
    for(int i = 1; i <= 9; i++)
    {
        fill(freq, freq + 10, 0);
        for(int j = 1; j <= 9; j++)
            freq[M[i][j]]++;

        for(int i = 1; i <= 9; i++)
            if(freq[i] != 1)
                return false;

        fill(freq, freq + 10, 0);
        for(int j = 1; j <= 9; j++)
            freq[M[j][i]]++;

        for(int i = 1; i <= 9; i++)
            if(freq[i] != 1)
                return false;
    }
    return true;
}

bool cuad(int f, int c)
{
    fill(freq, freq + 10, 0);
    for(int i = f; i <= f + 2; i++)
        for(int j = c; j <= c + 2; j++)
            freq[M[i][j]]++;

    for(int i = 1; i <= 9; i++)
        if(freq[i] != 1)
            return false;
    return true;
}

bool checkcuadrants()
{
    if(cuad(1, 1) && cuad(1, 4) && cuad(1, 7)
    && cuad(4, 1) && cuad(4, 4) && cuad(4, 7)
    && cuad(7, 1) && cuad(7, 4) && cuad(7, 7))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen(".in", "r", stdin);

    int f = 1, c = 1;
    while(f <= 9){
        c = 1;
        while(c <= 9){
            char car;
            cin >> car;
            if(car <= '9' && car >= '1')
            {
                M[f][c] = car - '0';
                c++;
            }
        }
        f++;
    }
    /*for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
            cout << M[i][j] << ' ';
        cout << endl;
    }*/

    if(filasycolumnas() && checkcuadrants())
        cout << "CORRECT\n";
    else
        cout << "WRONG\n";


    return 0;
}
