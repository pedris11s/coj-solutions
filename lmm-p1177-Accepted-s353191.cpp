//by pter

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char s[105];

int main()
{
    while(true)
    {
        int g;
        cin >> g;

        if(g == 0)
            break;

        cin >> s;
        int size = strlen(s);
		
		g = size / g; 
        for(int i = 0; i < size; i += g)
            reverse(s + i, s + i + g);

        cout << s << endl;
    }
    return 0;
}
