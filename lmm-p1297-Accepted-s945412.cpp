#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    int sol = 0;
    while(t--)
    {
        string N;
        cin >> N;

        int sum = 0;
        for(int i = 0; i < N.size(); i++)
            sum = (sum * 10 + (N[i] - '0')) % 495;

        if(sum == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
