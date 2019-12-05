//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		
		char c;
		if(n == m && n % 2 == 0)c = 'L';
		else if(n == m && n % 2 == 1) c = 'R';
		
		else if(n > m && n % 2 == 0 && m % 2 == 1)c = 'D';
		else if(n > m && n % 2 == 1 && m % 2 == 0)c = 'U';
	
		else if(n < m && n % 2 == 0 && m % 2 == 1)c = 'L';
		else if(n < m && n % 2 == 1 && m % 2 == 0)c = 'R';
	
		else if(n > m && n % 2 == 0 && m % 2 == 0)c = 'U';
		else if(n > m && n % 2 == 1 && m % 2 == 1)c = 'D';
		
		else if(n < m && n % 2 == 0 && m % 2 == 0)c = 'L';
		else if(n < m && n % 2 == 1 && m % 2 == 1)c = 'R';
		
		cout << c << '\n';
	}
}
