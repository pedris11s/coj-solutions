//by pter

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 15;

int main()
{
    string a, b;

    while(true)
    {
        cin >> a >> b;

        if(a[0] == '0' && b[0] == '0')
            break;

        int szA = a.length();
        int szB = b.length();

        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );

        int carry = 0;
        int llevo = 0;
        //cout << a << " "<< b << endl;
        for(int i = 0; i < max(szA, szB); i++)
        {
            int na = (i >= szA) ? 0 : a[i] - '0';
            int nb = (i >= szB) ? 0 : b[i] - '0';
            //cout << na << " " << nb << endl;
            int n = na + nb + llevo;
            if(n >= 10)
            {
                carry++;
                llevo = n / 10;
            }
            else
                llevo = 0;
        }
        if(carry == 0)
            cout << "No carry operation." << endl;
        else if(carry == 1)
            cout << "1 carry operation." << endl;
        else
            cout << carry << " carry operations." << endl;
    }

    return 0;
}
