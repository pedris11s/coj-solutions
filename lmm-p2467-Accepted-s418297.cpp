#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    while(true)
    {
        int a, b;
        cin >> a >> b;
        if(a == b && a == 0)
            break;

        if(a >= b)
            cout << "0\n";
        else
        {
            int cont = 0;
            while(a < b)
            {
                if(b / 2 >= a &&  b % 2 == 0)
                {
                    b /= 2;
                    cont++;
                }
                else if(b - 1 >= a)
                {
                    b--;
                    cont++;
                }
            }
            //if(a == b && a == 1)
            //    cont++;

            cout << cont << endl;
        }
    }
    return 0;
}
