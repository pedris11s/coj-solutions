#include <cstdio>
#include <iostream>

using namespace std;

int rev(int n)
{
    int num = 0;
    while(n > 0)
    {
        num = num * 10 + n % 10;
        n /= 10;
    }
    return num;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int a, b;
        cin >> a >> b;

        int sum = rev(a) + rev(b);
        cout << rev(sum) << endl;
    }
    return 0;
}
