#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

typedef long long LL;

int N, Q;
LL A[MAXN], tree[MAXN];

void update(int pos, LL val)
{
    for(int i = pos; i <= N; i += (i & -i))
        tree[i] += val;
}

LL query(int pos)
{
    LL sum = 0;
    for(int i = pos; i > 0; i -= (i & -i))
        sum += tree[i];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    for(int k = 1; k <= t; k++)
    {
        cin >> N >> Q;
        for(int i = 0; i <= N; i++)tree[i] = 0;

        for(int i = 1; i <= N; i++){
            cin >> A[i];
            update(i, A[i]);
        }
        cout << "Case " << k << ":\n";
        while(Q--)
        {
            LL q, idx, sol, v;
            cin >> q;
            if(q == 1)
            {
                cin >> idx;
                idx++;
                sol = query(idx) - query(idx - 1);
                cout << sol << "\n";
                update(idx, -sol);
            }
            else if(q == 2)
            {
                cin >> idx >> v;
                idx++;
                update(idx, v);
            }
            else
            {
                cin >> idx >> v;
                idx++, v++;
                sol = query(v) - query(idx - 1);
                cout << sol << "\n";
            }
        }
    }
    return 0;
}
