#include <cstdio>
#include <iostream>

using namespace std;

int max(int n)
{
    int i = 1;
    while(i - 1 < n)
        i *= 2;
    i /= 2;
    return i - 1;
}

int f(int k)
{
    //cout << k << endl;
    if(k < 2)
        return k;

    int a = max(k);
    int d = k - a;

    return d + f(a) + f(d - 1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        cout << f(b) - f(a - 1) << endl;
    }
    return 0;
}
