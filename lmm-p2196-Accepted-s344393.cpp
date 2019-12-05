#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string n;
    while(t--)
    {
        cin >> n;

        if(n[ n.size() - 1 ] & 1)
            cout << "odd\n";
        else
            cout << "even\n";
    }

    return 0;
}
