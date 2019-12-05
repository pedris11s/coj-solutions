#include <bits/stdc++.h>

using namespace std;

int main()
{
    string cad;
    cin >> cad;

    int a = 0, b = 0;
    int i = 0;
    while(i < cad.size())
    {
        if(cad[i] == 'a'){
            a++;
            while(cad[i] == 'a')
                i++;
        }
        i++;
    }
    i = 0;
    while(i < cad.size())
    {
        if(cad[i] == 'b'){
            b++;
            while(cad[i] == 'b')
                i++;
        }
        i++;
    }
    cout << min(a, b) << "\n";
    return 0;
}
