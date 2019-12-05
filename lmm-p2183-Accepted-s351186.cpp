#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    cin >> t;
    scanf("\n");

    while(t--)
    {
        string s;
        getline(cin, s);

        int even = 0, odd = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        if(even > odd)
            cout << "Even" << endl;
        else
            cout << "Odd" << endl;
    }

    return 0;
}
