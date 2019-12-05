#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int to_num(string aux)
{
    int p = 1;
    int num = 0;
    for(int i = aux.size() - 1; i > -1; i--)
    {
        num += (aux[i] - '0') * p;
        p *= 10;
    }
    return num;
}

char cad[150];
int sol[3];

void f1(char cad[], int size)
{
    stack <int> pila;
    queue <int> cola;
    priority_queue <int, vector <int>, greater <int> > pcola;

    for(int i = 0; i < size; i++)
    {
        if(cad[i] == ' ')continue;

        string aux = "";

        if(cad[i] == '+' || cad[i] == '-' || cad[i] == '*')
        {
            int ap = pila.top();
            pila.pop();

            int bp = pila.top();
            pila.pop();

            int ac = cola.front();
            cola.pop();

            int bc = cola.front();
            cola.pop();

            int apc = pcola.top();
            pcola.pop();

            int bpc = pcola.top();
            pcola.pop();

            if(cad[i] == '+')
            {
                pila.push(bp + ap);
                cola.push(bc + ac);
                pcola.push(bpc + apc);
            }
            else if(cad[i] == '-')
            {
                pila.push(bp - ap);
                cola.push(bc - ac);
                pcola.push(bpc - apc);
            }
            else
            {
                pila.push(bp * ap);
                cola.push(bc * ac);
                pcola.push(bpc * apc);
            }
        }
        else
        {
            while(cad[i] >= '0' && cad[i] <= '9')
                aux += cad[i], i++;

            int num = to_num(aux);
            //cout << num << endl;
            pila.push(num);
            cola.push(num);
            pcola.push(num);
        }
    }
    sol[0] = pila.top();
    sol[1] = cola.front();
    sol[2] = pcola.top();
}

int main()
{
    //freopen("d.in", "r", stdin);

    int t;
    scanf("%d", &t);
    scanf("\n");
    while(t--)
    {
        cin.getline(cad, 115, '\n');
        f1(cad, strlen(cad));
        cout << sol[0] << ' ' << sol[1] << ' ' << sol[2] << endl;
    }

    return 0;
}
