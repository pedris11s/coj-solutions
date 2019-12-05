#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100007;

int N, K, A[MAXN];
long long tree[2 * MAXN];

void update(int pos)
{
    for(int i = pos + MAXN; i < 2 * MAXN; i += (i & -i))
        tree[i]++;
}

long long query(int pos)
{
    long long sum = 0;
    for(int i = pos + MAXN; i > 0; i -= (i & -i))
        sum += tree[i];
    return sum;
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        A[i] = (x < K) ? -1 : 1;
    }
    update(0);
    long long sol = 0, sum = 0;
    for(int i = 1; i <= N; i++)
    {
        sum += A[i];
        sol += query(sum);
        update(sum);
    }
    cout << sol << endl;

    return 0;
}
