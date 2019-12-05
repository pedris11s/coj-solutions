#include <bits/stdc++.h>

using namespace std;

int diamonds[1000];

int main() {
	//freopen("f", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> diamonds[i];
	}
	sort(diamonds, diamonds + n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 1;
		for (int j = i + 1; j < n && diamonds[j] - diamonds[i] <= k; ++j) {
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
