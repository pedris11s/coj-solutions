#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int ini = 1, fin = M, sol = 0;
    for(int i = 0; i < K; i++)
    {
        int x;
        cin >> x;
        if(ini <= x && fin >= x)continue;
        if( x < ini )
        {
            sol += ini - x;
            fin -= (ini - x);
            ini = x;
        }
        else
        {
            sol += x - fin;
            ini += (x - fin);
            fin = x;
        }
    }
    cout << sol << "\n";

    return 0;
}
