#include <cstdio>
#include <iostream>

using namespace std;

int sum(int n)
{
    if(n == 0)
        return 0;
    return (n * (n + 1)) / 2;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, n;
        cin >> a >> n;
        int sol = (a + sum(n - 1)) % n;
        if(sol == 0)
            sol = n;
        cout << sol << endl;
    }

    return 0;
}
