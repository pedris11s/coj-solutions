#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

bool jail[150];

int main()
{
    int t;
    cin >> t;

    int n;

    for(int k = 0; k < t; k++)
    {
        cin >> n;

        fill(jail, jail + 150, 0);

        int cont = n;

        for(int i = 2; i <= n; i++)
            for(int j = i; j <= n; j += i)
            {
                if( jail[j] == 0)
                {
                    jail[j] = true;
                    cont--;
                }
                else
                {
                    jail[j] = false;
                    cont++;
                }
            }
        cout << cont << '\n';
    }

    return 0;
}
