#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 10000005;

long long cantZ_2(long long n)
{
    long long sum = 0;
    long long pot = 5;
    while(n / pot != 0)
    {
        sum += n / pot;
        pot *= 5;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        cout << cantZ_2(n) << endl;
    }
    return 0;
}
