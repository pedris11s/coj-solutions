#include <bits/stdc++.h>
using namespace std;

int F(int n){
if(n==1) return 1;
return (1+F(n/2));
}

int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


	int t,k;
	cin>>t;
	while(t--){
        cin>>k;
        int val = log2(k) + 1;
        cout<<val<<"\n";
     //   cout<<F(k)<<"\n";

	}

	return 0;
}
