#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int r;
    cin >> r;
    r *= 4;

    string cad = "A";
    while(r--)
        cad += "a";
    cad += "h";
    cout << cad;


    return 0;
}
