#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 50007;
const LL MOD = 1000000007;

bool comp[MAXN];
LL F[MAXN];
vector <int> primes;

void criba()
{
    for(int i = 4; i < MAXN; i += 2)
        comp[i] = true;

    for(int i = 3; i * i < MAXN; i += 2)
        if(!comp[i])
            for(int j = i * i; j < MAXN; j += i + i)
                comp[j] = true;

    primes.push_back(2);
    for(int i = 3; i < MAXN; i += 2)
        if(!comp[i])
            primes.push_back(i);
    primes.push_back(MAXN);
    //cout << primes.size() << endl;
}

LL expMod(int b, int e)
{
    if(e == 0)
        return 1LL;
    if(e & 1)
        return (b * expMod(b, e - 1)) % MOD;
    LL r = expMod(b, e / 2);
    return (r * r) % MOD;
}

LL invMod(int p)
{
    LL x = expMod(p, MOD - 2);
    return x;
}

LL expFact(int n, int p)
{
	LL sol = 0;
	while(n / p > 0)
    {
		sol += n / p;
		n /= p;
	}
	return sol;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    criba();
    //cout << expFact(100, 5) << endl;
    F[0] = 1LL;
    for(int i = 1; i < MAXN; i++)
        F[i] = (F[i - 1] * i) % MOD;

    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;

        LL sol = 1;
        for(int i = 0; primes[i] <= N; i++)
        {
            LL e = expFact(N, primes[i]);
            LL x = expMod(primes[i], e + 1) - 1;
            sol *= x;
            sol %= MOD;
            sol *= invMod(primes[i] - 1);
            sol %= MOD;
        }
        sol -= F[N];
        sol += MOD;
        sol %= MOD;

        cout << sol << "\n";
    }

    return 0;
}
