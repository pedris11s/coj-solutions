#include <bits/stdc++.h>

using namespace std;

const int MAX_SQRT = 1007;

bool comp[MAX_SQRT];
int primes[1000];

bool is_prime(int n)
{
    if(n == 2)return true;
    if(n % 2 == 0)return false;

    for(int i = 3; i * i <= n; i+= 2)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int sol = 0;
        if(n % 2 == 0)
            sol++;

        for(int i = 3; i <= n; i += 2){
            if(is_prime(i) && n % i == 0)
                sol++;
        }
        cout << sol << endl;
    }

    return 0;
}
