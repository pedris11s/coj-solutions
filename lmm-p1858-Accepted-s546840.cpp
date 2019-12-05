#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

LL dp[10004], a[10004], K, CN = 0;

LL count_change(LL K, LL M)
{
    dp[0] = 1;
    for(int i = 0; i< CN; i++)
        for(int j = a[i]; j <= K; j++)
            dp[j] = (dp[j] + dp[j - a[i]]) % M;

    return dp[K];
}

int main()
{
    LL N, A, B, M;
    cin >> N >> A >> B >> M;
    for(int i = A; i <= B; i++)
        a[CN++] = i;

    cout << count_change(N, M) << endl;

    return 0;
}
