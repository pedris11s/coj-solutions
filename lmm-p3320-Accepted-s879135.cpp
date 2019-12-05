#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e9 + 7;

typedef unsigned long long LL;

vector <LL> sq;
LL sqsum[500000];

LL sum(LL n)
{
    return (n & 1) ? ((n + 1) / 2 * n) : ((n / 2) * (n + 1));
}

LL sumint(LL a, LL b)
{
    return sum(b) - sum(a - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i = 0;
    while(i * i < MAXN)
        sq.push_back(i * i), i++;

    for(int i = 1; i < sq.size(); i++)
        sqsum[i] = sqsum[i - 1] + sq[i];

    //cout << sumint(9, 9) << endl;

    while(true)
    {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;

        int pa = lower_bound(sq.begin(), sq.end(), a) - sq.begin() - 1;
        int pb = upper_bound(sq.begin(), sq.end(), b) - sq.begin() - 1;

        LL x = sqsum[pb] - sqsum[pa];
        LL sol = sumint(a, b) - x;

        cout << sol << "\n";
  //      cout << pa << "  " << pb << endl;
    }
    return 0;
}
