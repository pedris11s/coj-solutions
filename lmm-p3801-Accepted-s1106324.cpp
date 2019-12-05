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
ll N, M , A[2005], B[2005];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	B[0]=1;
for(int i=1; i< 1005;i++)B[i]=B[i-1]+3;

ll t,s,u,d;
cin>>t;
while(t--){
	cin>>s>>A[0]>>A[1];
	for(int i=2; i < s;i++){
		A[i]=A[i-1]*A[i-2];
		A[i]%=1000000;
	}

	cout << "At week " << B[s-1] << " we obtain "<< A[s-1] <<" new rabbits.\n";
}
	return 0;
}
