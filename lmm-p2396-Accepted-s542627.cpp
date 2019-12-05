#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct par{
    int num, cost;
    par(int a = 0, int b = 0)
    {
        num = a, cost = b;
    }
    bool operator < (const par &X)const
    {
        return cost < X.cost;
    }
};

const int MAXN = (1 << 20) + 100;

int N, Num;

int Dijkstra()
{
    queue <par> cola;
    vector <int> costo(MAXN, (1 << 30));

    cola.push(par(Num, 0));
    costo[Num] = 0;
    while(!cola.empty())
    {
        int num = cola.front().num;
        int cost = cola.front().cost;
        cola.pop();

        if(num == (1 << N) - 1)
            return cost;

        for(int i = 0; i < N; i++)
        {
            int nn = num;
            if(nn & (1 << i))
                nn -= (1 << i);
            else
                nn += (1 << i);

            if(i != 0)
            {
                if(nn & (1 << (i - 1)))
                    nn -= (1 << (i - 1));
                else
                    nn += (1 << (i - 1));
            }

            if(i != N - 1)
            {
                if(nn & (1 << (i + 1)))
                    nn -= (1 << (i + 1));
                else
                    nn += (1 << (i + 1));
            }

            if(costo[nn] > cost + 1)
            {
                costo[nn] = cost + 1;
                cola.push(par(nn, cost + 1));
                //cout << costo[nn] << ") " << nn << endl;
            }

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
        cin >> N;
        Num = 0;
        for(int i = N - 1; i >= 0; i--)
        {
            char c;
            cin >> c;
            if(c == '1')
                Num += (1 << i);
        }
        int sol = Dijkstra();
        cout << sol << endl;
    }

    return 0;
}
