#include <bits/stdc++.h>

using namespace std;

int main()
{
    string zero = "0000000", one = "1111111";

    string cad;
    cin >> cad;

    if(cad.size() < 7){
        cout << "NO\n";
        return 0;
    }

    bool flag = false;
    for(int i = 0; i < cad.size() - 7; i++)
        if(cad.substr(i, 7) == zero || cad.substr(i, 7) == one){
            cout << "YES\n";
            flag = true;
            break;
        }

    if(!flag)
        cout << "NO\n";

    return 0;
}
