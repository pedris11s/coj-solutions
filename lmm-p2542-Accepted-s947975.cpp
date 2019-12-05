#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

struct matrix{
    LL A, B, C, D;
    matrix(){}
    matrix(LL A, LL B, LL C, LL D) {
        this -> A = A;
        this -> B = B;
        this -> C = C;
        this -> D = D;
    }
    const matrix operator * (const matrix &other){
        LL a, b, c, d;
        a = (A % MOD * (other.A % MOD)) % MOD + (B % MOD * (other.C % MOD)) % MOD;
        b = (A % MOD * (other.B % MOD)) % MOD + (B % MOD * (other.D % MOD)) % MOD;
        c = (C % MOD * (other.A % MOD)) % MOD + (D % MOD * (other.C % MOD)) % MOD;
        d = (C % MOD * (other.B % MOD)) % MOD + (D % MOD * (other.D % MOD)) % MOD;
        return matrix(a % MOD,b % MOD,c % MOD,d % MOD);
    }
};

const matrix FIB = matrix(0, 1, 1, 1);

matrix fib(const matrix b, LL e){
    if(e == 1)
        return b;
    matrix d = fib(b, e / 2);
    d = d * d;
    if(e & 1)
        d = d * b;
    return d;
}

LL lcm(LL a, LL b){
	return (a * b/__gcd(a,b));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;

        //int gcd = __gcd(a, b);
        //LL lcm = (a * b) / gcd;

        //int H = fib(FIB, (a * b) / __gcd(a, b)).B;
        //int K = fib(FIB, __gcd(a, b)).B;

        //cout << H << " " << K << "\n";

        printf("%lld %lld\n",fib(FIB, lcm(a,b)).B, fib(FIB, __gcd(a,b)).B);
    }

    return 0;
}


