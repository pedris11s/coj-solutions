#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int MAX_SQRT = 1000007;

bool comp[MAX_SQRT];
vector <LL> primes;

void criba()
{
	comp[1] = true;
	for(LL i = 4; i < MAX_SQRT ; i += 2)
		comp[i] = true;

	for(LL i = 3; i * i < MAX_SQRT; i += 2)
		if (!comp[i])
			for (LL j = i * i ; j < MAX_SQRT; j += i + i)
				comp[j] = true;

	primes.push_back(2);
	for(LL i = 3; i < MAX_SQRT; i += 2)
		if(!comp[i])
			primes.push_back(i);
}

bool is_prime(LL n)
{
    if(n == 1)return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;

    for(LL i = 0; primes[i] * primes[i] <= n; i++)
        if(n % primes[i] == 0)
            return false;
    return true;
}


int main()
{
    //freopen("d.in", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(0);

    criba();

    int t;
    cin >> t;
    while(t--)
    {
        LL n;
        cin >> n;
        if(is_prime(n - 2))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
