//hecho en contest

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

int main()
{
    /*huge sol = 100000;
    cout << sol * (sol + 1) / 2;*/

    while(true)
    {
        huge n;
        cin >> n;
        if(n == 0)
            break;

        if(n == 1)
            cout << "1\n";
        else
        {
            bool flag = false;
            huge ini = 1, fin = 100000;
            huge mit;
            while(fin - ini > 0)
            {
                mit = (ini + fin) / 2;
                huge a = (mit - 1) * mit / 2;
                huge b = mit * (mit + 1) / 2;
                if(n <= a)
                    fin = mit - 1;
                else if(n >= b)
                    ini = mit + 1;
                else if(a < n && n < b)
                {
                    cout << mit << endl;
                    //cout <<  "mit " << mit << endl;
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                int aux = ((ini - 1) * ini / 2);
                if(aux == n)
                    ini--;
                cout << ini << endl;
                //cout << "ini " << ini << " aux " << aux << endl;
            }

        }
    }


    return 0;
}
