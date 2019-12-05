#include <bits/stdc++.h>
#define MAX_N 100005

using namespace std;

int A[MAX_N];
pair<int, int> tree[MAX_N << 2];

void build(int n, int b, int e)
{
    if(b == e)
    {
        tree[n] = {b, b};
        return;
    }
    int h = (b + e) >> 1, l =  n << 1, r = l + 1;
    build(l, b, h);
    build(r, h + 1, e);
    tree[n].first = A[tree[l].first] < A[tree[r].first]? tree[l].first: tree[r].first;
    tree[n].second = A[tree[l].second] > A[tree[r].second]? tree[l].second: tree[r].second;
}

void update(int n, int b, int e, int i, int j)
{
    if(b == e && e == i)
    {
        A[i] = j;
        return;
    }
    int h = (b + e) >> 1, l =  n << 1, r = l + 1;
    if(i <= h) update(l, b, h, i, j);
    else update(r, h + 1, e, i, j);
    tree[n].first = A[tree[l].first] < A[tree[r].first]? tree[l].first: tree[r].first;
    tree[n].second = A[tree[l].second] > A[tree[r].second]? tree[l].second: tree[r].second;
}

int r;

void query(int n, int b, int e, int i, int j, int k)
{
    if(b > j || e < i) return;
    if(b >= i && e <= j && A[tree[n].first] > k) return;
 
    if(b >= i && e <= j && A[tree[n].second] <= k)
    {
        r += e - b + 1;
        return;
    }
    int h = (b + e) >> 1, l =  n << 1, r = l + 1;
    query(l, b, h, i, j, k);
    query(r, h + 1, e, i, j, k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, i, j, k;
    string op;
    cin >> n >> q;
    for(i = 1; i <= n; i ++)
    {
        cin >> A[i];
    }
    build(1, 1, n);
    while(q --)
    {
        cin >> op >> i >> j;
        if(op[0] == 'C')
        {
            update(1, 1, n, i, j);
        }
        else
        {
            cin >> k;
            r = 0;
            query(1, 1, n, i, j, k);
            cout << r << "\n";
        }
    }
    return 0;
}
