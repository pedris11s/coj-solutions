#include <cstdio>
#include <iostream>

using namespace std;

string cad;
int pot2[32];

int sum(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += pot2[i];
    return sum;
}

int f(int k)
{
    int x = 0, cont = 0;
    for(int i = 1; i < 31; i++)
    {
        if(x >= k)
            break;

        x += pot2[i];
        cont++;
    }
    return cont;
}

void sol(int k)
{
    while(k != 0)
    {
        int pos = f(k);
        if(sum(pos - 1) + pot2[pos] / 2 >= k)
        {
            cad = cad + "4";
            k -= pot2[pos] / 2;
        }
        else
        {
            cad = cad + "7";
            k -= pot2[pos];
        }
    }
}

int main()
{
    int k;
    cin >> k;

    pot2[0] = 1;
    for(int i = 1; i < 31; i++)
        pot2[i] = pot2[i - 1] * 2;

    sol(k);
    cout << cad << endl;



    return 0;
}

