#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int ini, fin;

    for(int i = 0; i< t; i++)
    {
        cin >> ini >> fin;
        int cont = 0;
        for(int j = ini; j <= fin; j++)
            cont += __builtin_popcount(j);

        cout << cont << '\n';
    }

    return 0;
}
