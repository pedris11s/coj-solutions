#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    int D = b * b - 4 * a * c;

    if(D >= 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}
