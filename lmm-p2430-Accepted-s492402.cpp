#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long huge;

huge calc(huge n)
{
	if(n % 2 == 0)
        return (n / 2 ) * (n + 1);
	return ((n + 1) / 2) * n;
}

int main()
{
	huge n;
	while(cin >> n, n)
	{
		huge ini = 1, fin = 5656854249, mid;
		while(ini < fin)
		{
			mid = (ini + fin) / 2;
			if(calc(mid) < n)
				ini = mid + 1;
			else
				fin = mid;
		}

		huge num = calc(ini);
		if(n == num)
			printf("YES\n");
		else
			printf("NO\n");
	}



	return 0;
}
