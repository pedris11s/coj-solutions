#include <bits/stdc++.h>

using namespace std;

int a[1007], b[1007];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
            sum = max(sum, a[i] + b[i]);
        }
        int sol = 0;
        for(int i = 0; i < n; i++)
            sol += sum - (a[i] + b[i]);
        cout << sol << "\n";

    }

    return 0;
}
