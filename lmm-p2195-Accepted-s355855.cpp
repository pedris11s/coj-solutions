#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 100005;

int h[MAXN];
int sol[MAXN];
stack <int> pila;

int main()
{
//    freopen("2195.in", "r", stdin);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> h[i];
    /*for(int i = 1; i <= n; i++)
        cout << h[i] << endl;*/

    for(int i = n; i >= 1; i--)
    {
        //cout << i << endl;
        while( !pila.empty() && h[i] >= h[pila.top()] )
            pila.pop();

        if(pila.empty())
            sol[i] = 0;
        else
            sol[i] = pila.top();

        pila.push(i);
    }
    for(int i = 1; i <= n; i++)
        cout << sol[i] << endl;

    return 0;
}
