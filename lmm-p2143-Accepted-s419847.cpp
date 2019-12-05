#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000;

int dp[MAX + 1];

int main()
{
	int t, sol = 0;
    cin >> t;
	while(t--)
	{
		memset(dp, 0, sizeof dp);

		int n, m;
		cin >> n >> m;

		for(int i = 0; i < n; i++)
		{
			int w, c;
			cin >> w >> c;
			for(int j = m; j >= w; j--)
				dp[j] = max(dp[j], dp[j - w] + c);
		}
		int best = dp[0];
		for(int i = 1; i <= m; i++)
			best = max(best, dp[i]);

		sol += best;
	}
	cout << sol << endl;
}
