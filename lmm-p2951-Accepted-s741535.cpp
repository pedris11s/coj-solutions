#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 1e5 + 1;

int N;
string L[MAXN];

int main(){
	cin >> N;
	for (int i = 0 ; i < N ; i++)
		cin >> L[i];

	for (int i = 0 ; i < N ; i++)
		sort(L[i].begin(), L[i].end());

	sort(L, L + N);

	int sol = 1;
	for (int i = 1 ; i < N ; i++)
		if ( ! binary_search(L, L + i, L[i]) )
			sol++;

	cout << sol; 
	
	return 0;
}
