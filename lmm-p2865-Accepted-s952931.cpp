#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string cad;
    cin >> cad;
    int siz = cad.size();
    int a = 0, cont = 0;
    cad[siz] = cad[0];
    for(int i = 0; i < siz; i++)
    {
         if(cad[i] == '0')
         {
             if(cad[i+1] == '0')
                cont++;
            a++;
         }
    }

    if(cont * siz == a * a)
        cout << "EQUAL\n";
    if(cont * siz < a * a)
        cout << "ROTATE\n";
    if(cont * siz > a * a)
        cout << "SHOOT\n";

    return 0;
}
