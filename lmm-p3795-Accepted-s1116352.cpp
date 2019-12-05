#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 7;

int sol[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    for(int i = 2; i < MAXN; i++)
        for(int j = 1; j <= i / 2; j++)
            if(i % j == 0)
                sol[i] +=j;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        if(sol[n] < n)
            cout << "deficient\n";
        else if(sol[n] == n)
            cout << "perfect\n";
        else
            cout << "abundant\n";

    }

    return 0;
}
