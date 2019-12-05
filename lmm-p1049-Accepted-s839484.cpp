#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, sol;
    cin >> n;

    bool flag = false;
    if(n < 0)
        flag = true;

    if(n < 0)
        n = n * (-1);

    if(n % 2 == 0)
        sol = ((n / 2)) * (n + 1);
    else
        sol = ((n + 1) / 2) * n;

    if(flag)
        sol = 1 - sol;

    cout << sol << endl;



    return 0;
}
