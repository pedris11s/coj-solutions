#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

LL cantv(LL n, LL p)
{
    LL cont = 0;
    while(n / p > 0)
    {
        cont += n / p;
        n /= p;
    }
    return cont;
}

int main()
{
    LL A, B, P;
    while(cin >> A >> B >> P)
    {
        LL a = cantv(A - 1, P);
        LL b = cantv(B, P);
        cout << oct << b - a << endl;
    }

    return 0;
}

