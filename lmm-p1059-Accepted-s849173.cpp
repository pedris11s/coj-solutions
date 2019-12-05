#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(true)
    {
        int n;
        cin >> n;

        if(n == 0)
            break;

        string bin = "";
        while(n != 1)
        {
            if((n % 2) == 0)
                bin = "0" + bin;
            else
                bin = "1" + bin;

            n /= 2;
        }
        bin = "1" + bin;

        int cont = 0;
        for(int i = 0; i < bin.size(); i++)
            if(bin[i] == '1')
                cont++;

        cout << "The parity of " << bin << " is "<< cont << " (mod 2)." << endl;
        //cout << bin << endl;
    }
    return 0;
}
