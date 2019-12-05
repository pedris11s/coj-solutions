#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

inline int myabs(int n)
{
    return n > 0 ? n : -n;
}


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        if(s[s.length() - 1] == '0' || s[s.length() - 1] == '5')
        {
            int sumi = 0, sump = 0;
            for(int i = 0; i < s.length(); i++)
            {
                if(i & 1)
                    sumi += s[i] - 48;
                else
                    sump += s[i] - 48;
            }
            int value = myabs(sumi - sump);
            bool div3 = false;
            bool div11 = false;

            //cout << value << endl << sumi + sump << endl;

            if(value == 0 || value % 11 == 0)
                div11 = true;

            if( (sumi + sump) % 3 == 0 )
                div3 = true;

            if(div3 && div11)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}
