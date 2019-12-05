#include <bits/stdc++.h>

using namespace std;

int sol[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        sol[0] = sol[1] = sol[2] = 0;
        string cad;
        cin >> cad;
        for(int i = 0; i < cad.size(); i++){
            if(cad[i] == 'C')sol[0]++;
            else if(cad[i] == 'A')sol[1] += sol[0];
            else if(cad[i] == 'T')sol[2] += sol[1];
        }
        cout << sol[2] << "\n";
    }

    return 0;
}
