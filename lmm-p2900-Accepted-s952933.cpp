#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string cad;
    cin >> cad;

    string sol = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

    for(int i = 1; i < cad.size(); i++)
        for(int j = i + 1; j < cad.size(); j++)
        {
            string a = cad.substr(0, i);
            string b = cad.substr(i, j - i);
            string c = cad.substr(j);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            string aux = a + b + c;
            if(aux < sol)sol = aux;
        }
    cout << sol << "\n";

    return 0;
}
