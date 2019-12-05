#include <bits/stdc++.h>

using namespace std;

long long R[27];

int f(int n)
{
    int x = n * (n + 1) / 2;
    return x * x - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    R[1] = 1;
    for(int i = 2; i <= 20; i++)
        R[i] = R[i - 1] * i + 1;

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << R[n] << " " << f(n) << "\n";
    }

    return 0;
}
