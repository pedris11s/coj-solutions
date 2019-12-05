#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(true)
    {
        string sol = "";
        int n;
        cin >> n;

        if(n < 0)
            break;

        while(n > 0)
        {
            if(n % 3 == 0)
                sol = "0" + sol;
            else if(n % 3 == 1)
                sol = "1" + sol;
            else
                sol = "2" + sol;
             n /= 3;
        }
        //sol = "1" + sol;
        cout << sol << endl;
    }

    return 0;
}
