#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string n;
        cin >> n;
        if(n[n.size() - 1] == '0' || n[n.size() - 1] == '5')
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
