#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long huge;

//hasta aqui 63246 hay 6338 primos

const int sqrtMAX_SIEVE = 63246;
const int CP = 6340;

bool comp[sqrtMAX_SIEVE];
huge primes[CP];

void sieve()
{
	for (int x = 4 ; x < sqrtMAX_SIEVE ; x += 2)
		comp[x] = true;

	for (int p = 3 ; p * p < sqrtMAX_SIEVE ; p += 2)
		if (!comp[p])
			for (int k = p * p ; k < sqrtMAX_SIEVE ; k += p + p)
			{
				comp[k] = true;
			}
	
	primes[0] = 2;
	int ind = 1;
	for(int i = 3; i < sqrtMAX_SIEVE; i += 2)
		if(!comp[i])
			primes[ind++] = i;
					
	primes[ind] = sqrtMAX_SIEVE + 2;
}

bool PRIME(huge n)
{
	if(n == 1)return false;
	if(n == 2)return true;
	
	for(int i = 0; primes[i] * primes[i] <= n; i++)
		if(n % primes[i] == 0)
		{
			//cout << primes[i] << endl;
			return false;
		}
	return true;
}

int main()
{
	sieve();
	int t;
	cin >> t;
	
	while(t--)
	{
		huge n;
		cin >> n;
		
		if(n <= 2)
			cout << "2\n";
		else
		{
			if(n % 2 == 0 )
				n++;
				
			while(!PRIME(n))
				n += 2;
			
			cout << n << endl;
		}
	}
	return 0;
}
