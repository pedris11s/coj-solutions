//1552_fibonacci calculation

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define c11 first.first
#define c12 first.second
#define c21 second.first
#define c22 second.second

#define MKP(a, b) make_pair((a), (b))

typedef long long ll;
typedef pair <ll, ll> pii;
typedef pair <pii, pii> m22;

const ll MOD  = 1000000000;

m22 mult(m22 a, m22 b)
{
    m22 sol;

    sol.c11 = (a.c11 * b.c11 + a.c12 * b.c21) % MOD;
    sol.c12 = (a.c11 * b.c12 + a.c12 * b.c22) % MOD;
    sol.c21 = (a.c21 * b.c11 + a.c22 * b.c21) % MOD;
    sol.c22 = (a.c21 * b.c12 + a.c22 * b.c22) % MOD;

    return sol;
}

m22 pow2(m22 a, int n)
{
    if (n == 1)
        return a;

    if(n % 2 == 0)
    {
        m22 r = pow2(a, n / 2);
        return mult(r, r);
    }
    return mult(a, pow2(a, n - 1));
}

int main()
{
    ll t;
    cin >> t;

    m22 A = MKP(MKP(1, 1), MKP(1, 0));

    while(t--)
    {
        int n;
        cin >> n;

        m22 nM = pow2(A, n - 1);

        ll fibN = nM.c11;
        printf("%.9d\n", fibN);
        //cout << nM.c11 << ' ' << nM.c12 << endl;
        //cout << nM.c21 << ' ' << nM.c22 << endl;
    }
    return 0;
}

