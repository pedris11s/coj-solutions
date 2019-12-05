#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool is_correct1(string s)
{
    int i = 0;
    while(i < s.length())
    {
        if(!islower(s[i]))
            return false;

        i++;
    }
    return true;
}

bool is_correct2(string s)
{
    if(!isupper(s[0]))
        return false;

    int i = 1;
    while(i < s.length())
    {
        if(!islower(s[i]))
            return false;

        i++;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;

    if(is_correct1(s) || is_correct2(s))
        cout << s << endl;
    else
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(islower(s[i]))
                //s[i] -= 32;
                s[i] -= 32;
            else
                s[i] += 32;
        }
        cout << s << endl;
    }
    return 0;
}
