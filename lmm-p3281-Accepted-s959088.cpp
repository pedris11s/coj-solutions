#include <bits/stdc++.h>


using namespace std;

typedef long long LL;

const int MAXN = 1e6 + 7;

LL sum[MAXN];
int abi[MAXN];

void update(int pos)
{
    for(int i = pos; i < MAXN; i += (i & -i))
        abi[i] += 1;
}

int query(int pos)
{
    int sum = 0;
    for(int i = pos; i; i -= (i & -i))
        sum += abi[i];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 1; i < MAXN; i ++)
        sum[i] = i + sum[i - 1];

    for(int i = 1; i < MAXN; i ++)
    {
        LL val = 2 * sum[i - 1] + i;
        int pos = lower_bound(sum + i + 1, sum + MAXN, val) - sum;
        if(sum[pos] == val)
            update(pos);
    }
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;
        cout << query(n) << "\n";
    }
    return 0;
}
