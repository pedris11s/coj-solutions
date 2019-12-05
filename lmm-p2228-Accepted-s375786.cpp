//by pter

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

huge factoriza(huge n)
{
	huge k = 1;

	if(n % 2 == 0)
	{
		k *= 2;
		//cout << 2 << endl;
		while(n % 2 == 0)
			n /= 2;
	}
	for(huge i = 3; i * i <= n; i += 2)
		if(n % i == 0)
		{
			k *= i;
			//cout << i << endl;
			while(n % i == 0)
				n /= i;
		}
	
	k *= n;
	//cout << n << endl;
	return k;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		huge n;
		cin >> n;
		
		huge sol = factoriza(n);
		cout << sol << '\n';
	}
	
	return 0;
}
