#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    //freopen(".in", "r", stdin);

    string sol = "";
    char cad[2100];
    int print = 0;
    while(gets(cad))
    {
        int size = strlen(cad);
        int i = 0;
        while(i < size)
        {
            char c = cad[i];
            if(c == '#')
            {
                print++;
                i += 2;
                continue;
            }
            else if(c == '@')
            {
                print--;
                i += 2;
                continue;
            }

            if(print == 0)
                sol += cad[i];
            i++;
        }
        sol += "\n";
    }
    cout << sol.substr(0, sol.size() - 1);

    return 0;
}
