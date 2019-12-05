#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define REP(i, n) for (int i = 0 ; i < (n) ; i++)
#define FOR(i, a, b) for (int i = (a) ; i <= (b) ; i++)
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define RI(n) scanf("%d", &n)
#define RLL(n) scanf("%lld", &n)
#define PB push_back
#define MKP(a, b) make_pair(a, b)
#define X first
#define Y second

bool prime(int n){
	if (n == 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3 ; i * i <= n ; i += 2)
		if (n % i == 0)
			return false;
	return true;
}



int main()
{
	int n;
	
	RI(n);
	
	char sn[12];
	
	sprintf(sn , "%d", n);
	int len = strlen(sn);
	sort(sn, sn + len);
	
	int primality = 0;
	do{
		int psn = strtol(sn, NULL, 10);
		if (prime(psn))
			primality++;
	} while (next_permutation(sn, sn + len));
	
	printf("%d\n", primality);
	return 0;
}
