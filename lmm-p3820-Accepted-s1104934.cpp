#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int N, M;
int DP[MAXN], K[107];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;

    cin >> t;
    while(t--)
    {
        fill(DP, DP + MAXN, INT_MAX);
        cin >> N >> M;

        for(int i = 0; i < M; i++)
            cin >> K[i];

        DP[0] = 1;
        for(int j = 0; j < M; j++){
            for(int i = 0; i <= N; i++){
                if(i - K[j] < 0 || (DP[i - K[j]] == INT_MAX))
                    continue;
                DP[i] = min(DP[i], DP[i - K[j]] + 1);
            }
        }
        cout << DP[N] - 1 << "\n";
    }

    return 0;
}
