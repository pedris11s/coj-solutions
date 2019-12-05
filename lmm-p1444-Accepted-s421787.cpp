#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000001;

typedef long long huge;

struct array{
    int v;
    huge id;
    bool operator < (const array &X)const
    {
        return X.v > v;
    }
}A[MAXN];

int N, freq[MAXN];

int query(int pos)
{
    int sol = 0;
    for(int i = pos; i > 0; i -= (i & -i))
        sol += freq[i];
    return sol;
}

void update(int pos)
{
    for(int i = pos; i <= N; i += (i & -i))
        freq[i]++;
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i].v;
        A[i].id = i;
    }

    sort(A + 1, A + N + 1);

    huge sol = 0;
    for(int i = 1; i <= N; i++)
    {
        sol += (huge)query(N) - (huge)query(A[i].id);
        update(A[i].id);
    }
    cout << sol << endl;

    return 0;
}
