#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    string cad;
    cin >> cad;

    sort(cad.begin(), cad.end());
    reverse(cad.begin(), cad.end());

    //cout << cad << endl;

    if(cad[cad.size() - 1] == '0')
    {
        int sum = 0;
        for(int i = 0; i < cad.size(); i++)
            sum += (cad[i] - '0');
        if(sum % 3 == 0)
            cout << cad << "\n";
        else
            cout << "-1\n";
    }
    else
        cout << "-1\n";

    return 0;
}
