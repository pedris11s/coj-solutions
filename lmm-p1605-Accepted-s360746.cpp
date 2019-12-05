//by pter

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int grey_num(int pos)
{
    return pos ^ (pos / 2);
}

string to_bin(int n, int size)
{
    string sol = "";
    int p = size;
    while(n > 0)
    {
        sol = ((n & 1) ? '1' : '0') + sol;
        n >>= 1;
        p--;
    }
    if(sol.length() < size)
    {
        int i = 0;
        while(i < p)
        {
            sol = '0' + sol;
            i++;
        }
    }
    return sol;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;

        for(int i = 0; i < (1 << n); i++)
            cout << to_bin(grey_num(i), n);
        cout << endl;
    }
    return 0;
}
