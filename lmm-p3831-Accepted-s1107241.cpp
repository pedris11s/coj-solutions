#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    string per = "PER";
    string cad;
    cin >> cad;

    int sol = 0;
    for(int i = 0; i < cad.length(); i += 3){
        if(cad[i] != 'P')
            sol++;

        if(cad[i + 1] != 'E')
            sol++;

        if(cad[i +2] != 'R')
            sol++;
    }
    cout << sol << "\n";

    return 0;
}
