#include <iostream>

using namespace std;

int mod = 100999;
int DP[2005];

int main()
{
	DP[0] = 1;
	for(int i=1;i<=2000;i++)
		for(int j=2000;j>=i;j--){
			DP[j] += DP[j-i];
			if (DP[j] >= mod)
				DP[j] -= mod;
		}
	int cas,n;
	cin >> cas;
	while(cas--){
		cin >> n;
		cout << DP[n] << endl;
	}



	return 0;
}

