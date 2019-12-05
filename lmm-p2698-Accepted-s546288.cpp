#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string cad;
    cin >> cad;
    int sol = 0;
    for(int i = 0; i < cad.size(); i++)
        sol += (cad[i] - 'A' + 1);

    cout << sol << endl;

    return 0;
}
