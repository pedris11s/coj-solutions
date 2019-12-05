#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1002;

int x[MAXN], y[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int N, D;
        cin >> N >> D;

        cout << (int)D - (D / N) << endl;
    }

    return 0;
}
