#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int arr[MAXN], dp[MAXN];

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = N; i > -1; i--)
        dp[i] = max(dp[i + 1], dp[i + 2] + arr[i]);

    cout << dp[0] << "\n";

    return 0;
}
