#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 200005;

bool mk[MAX];

string bin(int n)
{
    string bin;
    while(n > 0)
    {
        bin = ((n & 1) ? "1" : "0") + bin;
        n /= 2;
    }
    return bin;
}

bool palindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while(i < j)
    {
        if(s[i] != s[j])
            return false;

        i++;
        j--;
    }
    return true;
}

int main()
{
    for(int i = 1; i < MAX; i++)
        if(palindrome(bin(i)))
            mk[i] = true;

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        bool ini = true;
        for(int i = a; i <= b; i++)
            if(mk[i])
            {
                if(ini)
                {
                    cout << i;
                    ini = false;
                }
                else
                    cout << " " << i;
            }
        cout << endl;
    }
    return 0;
}
