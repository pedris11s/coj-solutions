#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    while(cin >> n >> m){
        if(__gcd(n, m) == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
