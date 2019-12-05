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
#define ll long long
#define MAXN 1007
int N;
char A[MAXN];
int B[MAXN];
string s;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int maxx = 0;

	while(N--)
	{
		memset(A,sizeof(A),0);

		cin >> A;
		//cout << A << endl;
		maxx = 0;
		int t = strlen(A);
		//cout << t << endl;
		for(int i = 0 ; i < t; i++)
			B[i] = 0;
		for(int i = 1 ; i < t; i++)
			{
			if(A[i] - A[i-1] == 1)
				if (B[i-1] != 0 ) B[i] = B[i-1] + 1;
				else
					B[i] = 1;
				if(B[i] > B[maxx] || (B[i] == B[maxx] && A[i] < A[maxx]))
					maxx = i;
			}
		/*for(int i = 0 ; i < t; i++)
			cout << B[i] << " ";*/

		for(int i = (maxx - B[maxx]) ; i <= maxx ;i++)
		cout << A[i];
		cout << endl;

	}
	return 0;
}
