#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_SQRT = 31700;

bool comp[MAX_SQRT];
vector <LL> primes;

void criba()
{
    for(int i = 4; i < MAX_SQRT; i += 2)
        comp[i] = true;

    for(int i = 3; i * i < MAX_SQRT; i += 2)
        if(!comp[i])
            for(int j = i * i; j < MAX_SQRT; j += 2 * i)
                comp[j] = true;

    primes.push_back(2);
    for(int i = 3; i < MAX_SQRT; i += 2)
        if(!comp[i])
            primes.push_back(i);
    //cout << primes.size();
}

bool isPrime(LL n)
{
    if(n == 1)
        return false;

    for(int i = 0; primes[i] * primes[i] <= n; i++)
        if(n % primes[i] == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    criba();

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        for(LL i = a; i <= b; i++)
            if(isPrime(i))
                cout << i << "\n";
        cout << "\n";
    }

    return 0;
}
