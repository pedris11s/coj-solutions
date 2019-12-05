#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

string check(string s)
{
    string sol = "";
    for(int i = 0; i < s.size();  i++)
    {
        int ind = i, cont = 1;
        while(ind < s.size() - 1 && s[ind] == s[ind + 1])
            ind++, cont++;

        if(cont & 1)
            sol += s[i];
        else
            i = ind;
    }
    return sol;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        while(true)
        {
            string aux = s;
            s = check(s);
            if(s == aux)
            {
                cout << s << endl;
                break;
            }
        }
    }
    return 0;
}
