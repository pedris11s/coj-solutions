#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string cad;
    cin >> cad;
    int cont = 0, sol = 0;
    for(int i = 0; i < cad.size(); i++)
    {
        if(cad[i] == '(')
           cont++;
        else
        {
            if(cont == 0)
                sol++, cont++;
            else
                cont--;
        }
    }
    sol += cont / 2;
    cout << sol << endl;

    return 0;
}
