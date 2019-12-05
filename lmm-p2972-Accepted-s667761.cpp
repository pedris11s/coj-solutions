#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    //freopen(".out", "w", stdout);

    vector <int> V;
    V.push_back(1);
    int x = 1;
    for(int i = 1; i < 1000; i++)
    {
        V.push_back(V[i - 1] + x);
        x++;
    }

    int N;
    while(scanf("%d", &N) != EOF)
    {

        cout << V[N - 1];
        for(int i = N - 2; i > -1; i--)
            cout << ' ' << V[i];
        cout << endl;

    }

    return 0;
}

