#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string cad;
    cin >> cad;
    //cad = "+" + cad;
    int size = cad.length();

    string sol = "";
    if(size % 2 == 0)
    {
        for(int i = (size - 1) / 2; i > -1; i--)
            sol += cad[i];

        for(int i = size - 1; i >= (size - 1) / 2 + 1; i--)
            sol += cad[i];
    }
    else
    {
        for(int i = (size - 1) / 2 - 1; i > -1; i--)
            sol += cad[i];
        sol += cad[(size - 1) / 2];
        for(int i = size - 1; i >= (size - 1) / 2 + 1; i--)
            sol += cad[i];
    }
    cout << sol << endl;

    return 0;
}

