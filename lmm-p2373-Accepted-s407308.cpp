#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    double r[4], r0, r1, r2, r3;
    r[0] = r0 = a/b + c/d;
    r[1] = r1 = c/a + d/b;
    r[2] = r2 = d/c + b/a;
    r[3] = r3 = b/d + a/c;

    sort(r, r + 4);
    int sol;
    if(r[3] == r0)
        sol = 0;
    else if(r[3] == r1)
        sol = 1;
    else if(r[3] == r2)
        sol = 2;
    else
        sol = 3;

    cout << sol << endl;

    return 0;
}
