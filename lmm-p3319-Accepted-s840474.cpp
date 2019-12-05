#include <bits/stdc++.h>

using namespace std;

const int MAXN = 51;
typedef long long LL;

bool is_prime(int n)
{
    if(n == 0 || n == 1)return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;

    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

LL S[MAXN];

int main()
{
    //cout << (float)49/13 << endl;

    vector <int> P;

    P.push_back(2);
    for(int i = 3; i <= MAXN; i+= 2)
        if(is_prime(i))
            P.push_back(i);

    /*for(int i = 0; i < P.size(); i++)
        cout << P[i] << endl;*/

    S[0] = 1;
    for(int i = 1; i < MAXN; i++)
        if(is_prime(i))
            S[i] = S[i - 1] * i;
        else
            S[i] = S[i - 1];

    //for(int i = 0; i < MAXN; i++)
    //    cout << i << ") " << S[i] << endl;
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        cout << S[x] << endl;

    }

    return 0;
}
