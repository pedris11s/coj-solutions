#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

bool mkASCII[256];

int different(string s)
{
    //limpiando los arreglos de marca
    fill(mkASCII, mkASCII + 256, 0);

    int cont = 0;

    for(int i = 0; i < s.length(); i++)
        if(!mkASCII[s[i]])
        {
            mkASCII[s[i]] = true;
            cont++;
        }
    return cont;
}

int main()
{
    int t;
    cin >> t;
    string s;
    for(int i = 0; i < t; i++)
    {
        cin >> s;
        int sol = different(s);
        printf("%d\n", sol);
    }
    return 0;
}

