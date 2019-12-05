#include <bits/stdc++.h>
using namespace std;

#define N 50005

vector<int> va,vb;

int main() {

	double a = 0, b = 0;
	int la,lb,x;
	scanf("%d",&la);
	for ( int i = 0; i < la ; i++ ){
		scanf("%d",&x);
		va.push_back(x);
		a += log2(double(x));
	}
	scanf("%d",&lb);
		for ( int i = 0; i < lb ; i++ ){
			scanf("%d",&x);
			vb.push_back(x);
			b += log2(double(x));
		}

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	bool same = 1;
	for ( int i = 0; i < min(la,lb); i++ )
		same &= (va[i] == vb[i]);
	if ( same && la == lb ){
		printf("=\n");
	}else if ( a < b ){
		printf("<\n");
	}else{
		printf(">\n");
	}
	return 0;
}
