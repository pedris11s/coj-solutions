#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if(a % 2 == 0 && b % 2 == 0)
            cout << "Second\n";
        else if(a % 2 != 0 && b % 2 != 0)
            cout << "Second\n";
        else
            cout << "First\n";
    }


    return 0;
}
