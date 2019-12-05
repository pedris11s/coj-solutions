//by pter

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string rota(string s)
{
    char last = s[s.length() - 1];
    s = last + s;
    s = s.substr(0, s.length() - 1);
    return s;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int k;
        cin >> s >> k;

        while(k--)
            s = rota(s);

        cout << s << endl;
    }
    return 0;
}
