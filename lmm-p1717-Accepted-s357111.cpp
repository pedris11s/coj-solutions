//by pter

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

queue <int> cola;
int costo[10000];

string int_str(int n)
{
    char a[10];
    sprintf(a, "%d", n);
    return string(a);
}

int str_int(string n)
{
    int num = 0;
    int p = 1;
    for(int i = n.length() - 1; i >= 0; i--)
    {
        num += (n[i] - 48) * p;
        p *= 10;
    }
    return num;
}

bool prime(int n)
{
    if(n % 2 == 0)return false;
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;

    return true;
}

int prime_path(int ini, int dest)
{
    for(int i = 1000; i < 10000; i++)
        costo[i] = 0;

    while( !cola.empty() )
        cola.pop();

    cola.push(ini);
    costo[ini] = 1;

    while( !cola.empty() )
    {
        int n = cola.front();
        cola.pop();

        if(n == dest)
        {
            //cout << "GANEEEEEEE PEDRO" << endl;
            return costo[n] - 1;
        }
        string num = int_str(n);
        for(int i = num.length() - 1; i >= 0; i--)
        {
            char c = num[i];
            for(int j = 48; j <= 57; j++)
            {
                num[i] = j;
                int aux = str_int(num);
                if( prime(aux) && !costo[aux] )
                {
                    cola.push(aux);
                    costo[aux] = costo[n] + 1;
                    //cout << n << " " << aux << ' '<<costo[aux] << endl;
                    //system("pause");
                }
            }
            num[i] = c;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int sol = prime_path(a, b);
        /*for(int i = 1000; i < 10000; i++)
            if(costo[i] != 0)
                cout << i << ' ' << costo[i] << endl;*/
        cout << sol << endl;
    }


    return 0;
}
