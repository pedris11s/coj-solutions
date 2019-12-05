#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;string cad;
    cin >> n >> cad;

    int cont = 0;
    for(int i = 0; i < cad.size(); i++)
        if(islower(cad[i]))
            cont++;

    cout << n - cont << " " << cont << "\n";

    return 0;
}
