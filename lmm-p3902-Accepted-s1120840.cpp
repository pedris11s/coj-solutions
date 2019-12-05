#include <bits/stdc++.h>

using namespace std;
#define MAXN 1003
#define endl '\n'

double N , K , n , k;

int main(){

	ios_base::sync_with_stdio(0);cin.tie(0);

	cin >> N >> K >> n >> k;

	cout <<  int(int((N+ n- 0.000001)/ (n*2 - 0.000001)) * int((K+k-0.000001)/ (k*2 - 0.000001))) << endl;
	return 0;
}

