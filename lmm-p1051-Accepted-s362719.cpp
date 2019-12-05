#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	if(n % 3 == 0 || n % 3 == 1)
		cout << 2 * (n / 3) << '\n';
	else
		cout << 2 * (n / 3) + 1 << '\n';
	
	return 0;
}
