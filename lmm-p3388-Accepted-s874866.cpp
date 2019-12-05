#include <bits/stdc++.h>

using namespace std;

int to_int(string cad)
{
    int num = 0, p = 1;
    for(int i = cad.size() - 1; i > -1; i--)
    {
        num += (cad[i] - '0') * p;
        p *= 10;
    }
    return num;
}

string to_str(int n)
{
    string num = "";
    if(n == 0)
        return "0";
    while(n > 0)
    {
        num = char((n % 10) + '0') + num;
        n /= 10;
    }
    return num;
}

int main()
{
    /*int n;
    cin >> n;
    cout << to_str(n) << endl;
*/
    string cad;
    cin >> cad;

    int cont = 0;
    while(cad != "0")
    {
        string aux = cad;
        sort(aux.begin(), aux.end());
        int x = to_int(cad) - to_int(aux);
        cad = to_str(x);
        cont++;
    }
    cout << cont << endl;


    return 0;
}
