#include <bits/stdc++.h>

using namespace std;
long long n;
int main (){

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	if (n % 3LL == 0LL)
		cout << "Victor wins\n";
	else
		cout << "Kedir wins\n";


	return 0;
}
