#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int sol = 0;
    while(t--)
    {
        int n;
        cin >> n;
        sol += __builtin_popcount(n);
    }
    cout << sol << endl;

    return 0;
}
