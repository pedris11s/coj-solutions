#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL N, P;

LL exp(LL n, LL exp)
{
    LL p = exp, cont = 1;
    while(p <= n)
        p *= exp, cont++;
    return cont - 1;
}

LL pow(LL b, LL e)
{
    if(e == 0)
        return 1;
    if(e % 2 == 0)
    {
        LL r = pow(b, e / 2);
        return r * r;
    }
    return b * pow(b, e - 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int k = 1;
    while(cin >> N >> P)
    {
        if(N == 0 && N == P)
            break;

        LL x = pow(P, exp(N, P));
        //cout << x << endl;
        while(true)
        {

            if(N >= x){
                N -= x;
                //cout << x<< endl;
                if(N == 0){
                    cout << "Case #" << k << ":" << " yes\n";
                    k++;
                    break;
                }
            }
            x /= P;
            if(x == 0){
                cout << "Case #" << k << ":" << " no\n";
                k++;
                break;
            }
        }
    }

    return 0;
}
