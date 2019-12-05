#include <cstdio>
#include <iostream>

using namespace std;

long long fib[55];

int main()
{
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i < 55; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    while(true)
    {
        int n;
        cin >> n;

        if(n == 0)
            break;

        cout << fib[n + 1] << endl;
    }

    return 0;
}
