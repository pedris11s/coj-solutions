#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;
const int MAXN_SQRT = 1e3 + 7;

bool comp[MAXN], mk[MAXN];
int TA[MAXN];
vector <int> primes;

void criba()
{
    for(int i = 4; i * i < MAXN; i += 2)
        comp[i] = true;

    for(int i = 3; i * i < MAXN; i += 2)
        if(!comp[i])
            for(int j = i * i; j * j < MAXN; j += i + i)
                comp[j] = true;

    primes.push_back(2);
    for(int i = 3; i < MAXN; i += 2)
        if(!comp[i])
            primes.push_back(i);
}

bool isSpecial(int n)
{
    int cont = 0;
    for(int i = 0; primes[i] * primes[i] <= n; i++)
        if(n % primes[i] == 0)
        {
            int e = 0;
            while(n % primes[i] == 0)
            {
                n /= primes[i];
                e++;
                if(e > 1)
                    return false;
            }
            //cout << primes[i] << " " << e << endl;
            cont++;
        }
    if(n > 1){
        cont++;
        //cout << n << endl;
    }
    if(cont == 3)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    criba();
    //cout << isSpecial(30) << "\n";

    for(int i = 1; i < MAXN; i++){
        if(isSpecial(i))
            mk[i] = true;

        TA[i] += TA[i - 1] + mk[i];
    }

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        cout << TA[b] - TA[a - 1] << "\n";
    }

    return 0;
}
