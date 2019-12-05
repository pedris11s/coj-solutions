#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int p;
        cin >> p;
        if(p == 3)cout << "12\n";
        else cout << p + 3 << "\n";
    }
    return 0;
}
