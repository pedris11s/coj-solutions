#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 50007;

int wayf[MAXN];
vector <int> adlist[MAXN];
int lim_a, lim_b;

int main()
{
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        adlist[a].push_back(b);
        //lim_a = max(lim_a, a);
        //lim_b = max(lim_b, b);
    }
    for(int i = 1; i <= K; i++)
        sort(adlist[i].begin(), adlist[i].end());

    queue <int> cola;
    cola.push(1);
    while(!cola.empty())
    {
        int nodo = cola.front();
        cola.pop();

        for(int i = 0; i < adlist[nodo].size(); i++)
        {
            int nn = adlist[nodo][i];
            if(wayf[nn] != 0)
                continue;

            cola.push(nn);
            wayf[nn] = nodo;
        }
    }
    if(wayf[K] == 0)
        cout << "-1\n";
    else
    {
        vector <int> camino;
        int ini = 1, fin = K;
        while(fin != ini)
        {
            camino.push_back(fin);
            fin = wayf[fin];
        }
        camino.push_back(ini);

        cout << camino.size() << endl;
        for(int i = camino.size() - 1; i > -1; i--)
            cout << camino[i] << endl;
    }

    return 0;
}
