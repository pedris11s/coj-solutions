#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
const int MOD = 1000000007;
const int MAX = 1000005;

int fib[MAX];

int main()
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < MAX; i++)
        fib[i] = ( (fib[i - 1] % MOD) + (fib[i - 2] % MOD) ) % MOD;

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        cout << fib[n + 2] << endl;
    }
    return 0;
}
