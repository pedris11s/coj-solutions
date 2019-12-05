//by pter

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

int main()
{
    huge d, v;
    cin >> d >> v;

    if((v * (v - 3)) ==  2 * d)
        cout << "yes\n";
    else
        cout << "no\n";

    return 0;
}
