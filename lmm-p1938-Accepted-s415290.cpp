#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int huge;

const huge MAXN = 1000000000001;
const huge sqrtMAXN = 1000001;

bool comp[sqrtMAXN];
vector <huge> almost_prime;

void criba()
{
    for(huge i = 2; i * i < sqrtMAXN; i++)
        if(!comp[i])
            for(huge j = i * i; j < sqrtMAXN; j += i)
                comp[j] = true;
}

void sol()
{
    criba();
    for(huge i = 2; i < sqrtMAXN; i++)
        if(!comp[i])
            for(huge j = i * i; j < MAXN; j *= i)
                almost_prime.push_back(j);
}

int main()
{
    sol();
    int t;
    cin >> t;
    while(t--)
    {
        huge a, b;
        cin >> a >> b;
        huge cont = 0;
        for(int i = 0; i < almost_prime.size(); i++)
            if(almost_prime[i] >= a && almost_prime[i] <= b)
                cont++;
        cout << cont << endl;
    }

    return 0;
}

