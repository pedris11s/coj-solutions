#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int modulo(int n)
{
    return (n < 0) ? -n : n;
}


bool is_mult11(string cad)
{
    int sumP = 0, sumI = 0;
    for(int i = 1; i < cad.size(); i++)
    {
        if(cad[i] == '.')
            continue;
        if(i & 1)
            sumI += cad[i] - '0';
        else
            sumP += cad[i] - '0';
    }
    int value = modulo(sumP - sumI);
    if(value == 0 || value % 11 == 0)
        return true;
    return false;
}

int main()
{
    //freopen("asd.in", "r", stdin);

    string cad;
    cin >> cad;
    int p = 0;
    int i = 0;
    while(i++ < cad.size() || p == 0)
        if(cad[i] == 'X')
            p = i;

    for(char i = '0'; i <= '9'; i++)
    {
        cad[p] = i;
        //int num = to_num(cad);
        if(is_mult11(cad))
        {
            cout << cad << endl;
            break;
        }
    }




    return 0;
}
