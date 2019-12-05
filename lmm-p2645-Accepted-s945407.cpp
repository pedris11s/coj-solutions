#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(true)
    {
        string N;int B;
        cin >> B;
        if(B == 0)
            break;

        cin >> N;

        int sum = 0;
        for(int i = 0; i < N.size(); i++)
            sum += (N[i] - '0');

        int m = 0;
        for(int i = 0; i < N.size(); i++)
            m = (m * B + (N[i] - '0')) % sum;

        if(m == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
