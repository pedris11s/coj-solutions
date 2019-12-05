#include <cstdio>
#include <iostream>

using namespace std;

long long fib[50];

int main()
{
    fib[2] = 1;
    int k;
    cin >> k;
    for(int i = 3; i <= k + 2; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    cout << fib[k] << ' ' << fib[k + 1] << endl;



    return 0;
}
