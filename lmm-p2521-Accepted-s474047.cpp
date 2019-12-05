#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    bool a, b, c;
    while(cin >> a >> b >> c)
    {
        char sol;
        if(a != b && b == c)
            sol = 'A';
        else if(b != c && a == c)
            sol = 'B';
        else if(c != a && a == b)
            sol = 'C';
        else
            sol = '*';
        cout << sol << endl;

    }

    return 0;
}
