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


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	int cont,sum;
	string g;
	while(t--){
	cin>>g;
	cont=g.length();
	if(cont%2==0){
		cout<<"Non-inhabitant\n";
	}else{
		sum=cont;
		for(int i =1; i< cont;i+=2) sum+=i;
		cout<<"The inhabitant "<<g<<" can have "<<sum<<" children\n";
	}
	}

	return 0;
}
