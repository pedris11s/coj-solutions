#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    while(true)
    {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            break;

        int i = h1, j = m1;
        int cont = 0;
        while(i != h2 || j != m2)
        {
            cont++;
            j++;
            if(j == 60)
                j = 0, i++;

            if(i == 24)
                i = 0;
        }
        cout << cont << endl;

    }


    return 0;
}
