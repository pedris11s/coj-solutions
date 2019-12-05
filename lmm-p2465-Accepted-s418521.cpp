#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const char HEX[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int to_dec(char n)
{
    for(int i = 0; i < 16; i++)
        if(n == HEX[i])
            return i;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string numa, numb;
        cin >> numa >> numb;

        int sza = numa.length();
        int szb = numb.length();

        reverse(numa.begin(), numa.end());
        reverse(numb.begin(), numb.end());

        int sol = 0;
        int carry = 0;
        for(int i = 0; i < max(sza, szb); i++)
        {
            int na = (i >= sza) ? 0 : to_dec(numa[i]);
            int nb = (i >= szb) ? 0 : to_dec(numb[i]);

            int nn = na + nb + carry;
            if(nn >= 16)
            {
                sol++;
                carry = 1;
            }
            else
                carry = 0;
        }
        //if(carry == 1)
        //    sol++;
        cout << sol << endl;
    }
    return 0;
}
