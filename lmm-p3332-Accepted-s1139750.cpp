#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;

int pot(int e)
{
    if(e == 0)
        return 1;
         LL r;    

         r = pot(e / 2);
        
    if(e & 1)
    return (2LL * r * r) % MOD;
    return (r * r) % MOD;
}

int factoriza(int n)
{
    int sol = 0;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            sol++;
        }
    if(n > 1)
        sol++;
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if(a == b)
            cout << "1\n";
        else if(b % a != 0 || b < a)
            cout << "0\n";
        else
        {
            int e = factoriza(b / a);
            cout << pot(e - 1) << "\n";
        }

    }
    return 0;
}
