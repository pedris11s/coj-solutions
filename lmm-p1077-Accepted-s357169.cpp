//by pter

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int mCiclo[MAXN];

int ciclo(int n)
{
    int cont = 1;
    while(n != 1)
    {
        if(n & 1)
        {
            cont++;
            n = 3 * n + 1;
        }
        else
        {
            cont++;
            n /= 2;
        }
    }
    return cont;
}

int main()
{
    int a, b;
    while(cin >> a >> b)
    {
        bool change = false;
        if(a > b)
        {
            swap(a, b);
            change = true;
        }
        int max = 0;
        for(int i = a; i <= b; i++)
        {
            int c = ciclo(i);
            if(c > max)
                max = c;
        }
        if(change)
            cout << b << ' ' << a << ' ' << max << endl;
        else
            cout << a << ' ' << b << ' ' << max << endl;
    }

    return 0;
}
