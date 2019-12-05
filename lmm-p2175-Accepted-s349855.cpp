//by pter

#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 100005;

bool is_prime(int n)
{
    if(n == 0 || n == 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;

    return true;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        int a, b;

        for(int i = n; i > 1; i--)
            if( is_prime(i) )
            {
                a = i;
                break;
            }

        for(int i = n; i < MAX; i++)
            if( is_prime(i) )
            {
                b = i;
                break;
            }

        cout << a << ' ' << b << '\n';
    }
    return 0;
}
