#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string a, b;
    while(cin >> a >> b)
    {
        int ptr = 0;
        for(int i = 0; i < (int)b.size(); i++)
        {
            if(b[i] == a[ptr])
                ptr++;

            if(ptr == (int)a.size())
            {
                cout << "Yes\n";
                break;
            }

        }
        if(ptr < (int)a.size())
            cout << "No\n";
    }


    return 0;
}
