//by pter
//algorithm: floyd_warshall

#include <cstdio>
#include <iostream>
#include <ctype.h>

using namespace std;

int d[60][60];

const int INF = 99999;

int chartonum(char a)
{
    if(isupper(a))
        return a - 'A';
    else
        return a - 'a' + 26;
}

int main()
{
    for(int i = 0; i < 52; i++)
        for(int j = 0; j < 52; j++)
            d[i][j] = INF;

    for(int i = 0; i < 26; i++)
        d[i][i] = 0;

    int n, dist;
    char a, b;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> dist;
        int auxa = chartonum(a);
        int auxb = chartonum(b);

        if(d[auxa][auxb] > dist)
            d[auxa][auxb] = d[auxb][auxa] = dist;
    }

    for(int k = 0; k < 52; k++)
        for(int i = 0; i < 52; i++)
            for(int j = 0; j < 52; j++)
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    a = '&';
    dist = INF;
    for(int i = 'A'; i <= 'Y'; i++)
        if(d[chartonum(i)][chartonum('Z')] < dist)
        {
            dist = d[chartonum(i)][chartonum('Z')];
            a = i;
        }

    cout << a << ' ' << dist << endl;

    return 0;
}

