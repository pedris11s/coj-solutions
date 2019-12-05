#include <cstdio>
#include <iostream>

using namespace std;

int main()
{   int i = 1;
    while(true)
    {
        long long n;
        scanf("%lld", &n);
        if(n == 0)
            break;

        long long  d = ( n * (2 * n + 1) * (n + 1) ) / 6;

        printf("Case %d:\nn = %lld, diamonds = %lld\n", i, n, d);

        i++;
    }
    return 0;
}
