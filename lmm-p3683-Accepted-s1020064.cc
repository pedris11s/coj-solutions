#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	
	multiset <int> s;
	s.insert(0);
	s.insert(1000000);
	
	while(n--) {
		int x; scanf("%d", &x);
		
		auto l = s.lower_bound(x);
		auto u = --s.upper_bound(x);
		printf("%d %d\n", *u, *l);
		s.insert(x);
	}
	
	return 0;
}
