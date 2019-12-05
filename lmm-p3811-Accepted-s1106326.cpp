//============================================================================
// Name        : asdf.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int N, M , A[2000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for(int i = 0 ; i < N ;i++)
		cin >> A[i];

	bool flag = false;
	for(int i = 0 ; i < N-2; i++)
		for(int j = i+1 ; j < N-1; j++)
			for(int k = j+1 ; k < N; k++)
				if(((A[i]^A[j])^A[k]) == M)
					{
						flag = true;break;
					}
	if(flag) cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
