#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000003;
const int MOD = 1000007;

int N;
bool mk[MAXN];
vector <int> primes;

void criba()
{
    for(int i = 4; i * i < MAXN; i += 2)
        mk[i] = true;

    for(int i = 3; i * i < MAXN; i += 2)
        if(!mk[i])
            for(int j = i * i; j < MAXN; j += i + i)
                mk[j] = true;

    primes.push_back(2);
    for(int i = 3; i < MAXN; i += 2)
        if(!mk[i])
            primes.push_back(i);

    primes.push_back(MAXN + 7);
}

int exp(int n, int p)
{
    int cont = 0;
    while(n / p > 0)
    {
        cont += n / p;
        n /= p;
    }
    return cont;
}

int main()
{
    criba();

    int t;
    cin >> t;
    while(t--)
    {
        cin >> N;
        long long d = 0, w = 1;
        for(int i = 0; primes[i] <= N; i++)
        {
            long long x = (long long)exp(N, primes[i]);
            w = ((x * (x + 1) / 2) * w) % MOD;
            d++;
        }
        cout << d << ' ' << w << endl;
    }

    return 0;
}
