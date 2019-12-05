#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, cont = 0;

    cin >> n;
    if (n == 1) cont = -1;
    while (n > 3)
    {
           cont++;
           n = n / 3 + n % ((n / 3) * 3);
    }
    cont++;

    cout << cont << "\n";

    return 0;
}
