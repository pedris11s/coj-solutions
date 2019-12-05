#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <LL, LL> par;

const int MAXN = 1e5 +3;

par Q[MAXN]; LL A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < q; i++)
        cin >> Q[i].first >> Q[i].second;

    for(int i = 1; i <= n; i++)
        cin >> A[i];

    for(int i = q - 1; i > -1; i--)
        swap(A[Q[i].first], A[Q[i].second]);

    cout << A[1];
    for(int i = 2; i <= n; i++)
        cout << " " << A[i];
    cout << "\n";


    return 0;
}
