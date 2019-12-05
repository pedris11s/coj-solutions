#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a = -1, b = 2 + n / 2, c = (n + m) * -1;
    int d = b * b - 4 * a * c;

    int l = (-b - (int)sqrt(d)) / 2 * a;
    int w = (-b + (int)sqrt(d)) / 2 * a;
    cout << l << ' ' << w << endl;

    return 0;
}
