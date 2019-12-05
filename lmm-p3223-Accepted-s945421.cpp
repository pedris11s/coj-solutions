#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector <LL> p, e;

void factoriza(LL n)
{
    p.clear();
    e.clear();

    LL exp = 0;
    if(n % 2 == 0)
    {
        while(n % 2 == 0)
            exp++, n /= 2;
        p.push_back(2);
        e.push_back(exp);
    }
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
        {
            exp = 0;
            while(n % i == 0)
                exp++, n /= i;
            p.push_back(i);
            e.push_back(exp);
        }
    if(n > 1)
    {
        p.push_back(n);
        e.push_back(1);
    }
}

LL pow(LL b, LL e)
{
    if(e == 0)
        return 1LL;
    if(e % 2 == 0)
    {
        LL r = pow(b, e / 2);
        return r * r;
    }
    return b * pow(b, e - 1);
}

LL F(LL p, LL n)
{
    return (pow(p, n + 1) - 1) / (p - 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        LL n;
        cin >> n;
        factoriza(n);

        LL sol = 1;
        for(int i = 0; i < p.size(); i++)
            sol *= F(p[i], e[i]);
        cout << sol << "\n";

        /*for(int i = 0; i < p.size(); i++)
            cout << p[i] << "^" << e[i] << ' ';
        cout << endl;*/
    }

    return 0;
}
