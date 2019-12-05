#include <bits/stdc++.h>

using namespace std;

//(p^(alf + 1) - 1) / (p - 1)

typedef long long LL;
const int MAXN = 1e6 + 7;
const int MAX = 1e3 + 7;

int aux[MAXN];
bool comp[MAXN];
vector <LL> primes;

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
    //cout << primes.size() << endl;;
}

LL pow(LL b, LL e){
    if(e == 0)
        return 1;
    if(e % 2 == 0){
        LL r = pow(b, e / 2);
        return r * r;
    }
    return b * pow(b, e - 1);
}

LL sumDiv(LL n){
    LL sol = 1;
    for(int i = 0; primes[i] * primes[i] <= n; i++)
        if(n % primes[i] == 0){
            LL e = 0;
            while(n % primes[i] == 0){
                e++, n /= primes[i];
            }
            LL val = pow(primes[i], e + 1) - 1;
            sol *= (val) / (primes[i] - 1);
        }
    if(n > 1){
        sol *= ((n * n) - 1) / (n - 1);
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    /*for(int i = 2; i < MAX; i++)
        for(int j = 1; j <= i / 2; j++)
            if(i % j == 0)
                aux[i] +=j;
*/
    criba();
    int t;
    cin >> t;
    while(t--){
        LL n;
        cin >> n;
        LL sol = sumDiv(n) - n;
        //cout << sol << ' ' << aux[n] << endl;
        if(sol < n)
            cout << "deficient\n";
        else if(sol == n)
            cout << "perfect\n";
        else
            cout << "abundant\n";
    }


    return 0;
}

