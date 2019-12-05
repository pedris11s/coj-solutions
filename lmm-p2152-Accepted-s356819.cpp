//by pter

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string n;
        cin >> n;

        int sol = 0;
        int i = 0;
        if(n[0] == '-')
            i++;

        for( ; i < n.length(); i++)
            sol += n[i] - 48;

        cout << sol << endl;
    }
    return 0;
}
