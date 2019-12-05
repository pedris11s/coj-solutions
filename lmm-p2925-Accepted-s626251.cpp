#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

const int MAXN = 1e6 + 7;

int costo[MAXN];
bool mk[MAXN];
int a, b;

int bfs()
{
    queue <int> cola;
    fill(mk, mk + MAXN, false);
    fill(costo, costo + MAXN, 0);

    cola.push(a);
    mk[a] = true;
    costo[a] = 0;
    while(!cola.empty())
    {
        int num = cola.front();
        cola.pop();

        if(num == b)
            return costo[num];

        int nn = num + 1;
        if(!mk[nn])
        {
            costo[nn] = costo[num] + 1;
            mk[nn] = true;
            cola.push(nn);
        }
        nn = num / 2;
        if(!mk[nn])
        {
            costo[nn] = costo[num] + 1;
            mk[nn] = true;
            cola.push(nn);
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
        cin >> a >> b;
        cout << bfs() << endl;
    }

    return 0;
}

