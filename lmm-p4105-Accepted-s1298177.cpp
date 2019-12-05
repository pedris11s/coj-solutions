#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL calc(LL n){
	if(n & 1) 
		return (n + 1) / 2 * n;
	return n / 2 * (n + 1);
}

int main(){
   
	int n;
	cin >> n;
	LL sum = 0;	
	for(int i = 0; i < n - 1; i++){
		int x; cin >> x;
		sum += x;
	}

	LL sol = calc(n) - sum;
	cout << sol << "\n";

	return 0;
}