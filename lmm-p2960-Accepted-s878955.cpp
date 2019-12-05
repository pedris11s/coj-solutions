#include <bits/stdc++.h>

using namespace std;

int V[30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    V['A' - 'A'] = 1;
    V['B' - 'A'] = 2;
    V['D' - 'A'] = 1;
    V['O' - 'A'] = 1;
    V['P' - 'A'] = 1;
    V['Q' - 'A'] = 1;
    V['R' - 'A'] = 1;

    string cad;
    cin >> cad;

    int sol = 0;
    for(int i = 0; i < cad.size(); i++)
        sol += V[cad[i] - 'A'];
    cout << sol << "\n";




    return 0;
}
