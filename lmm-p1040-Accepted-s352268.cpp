//by pter
//user:lmm
//algorithm: Ordenamiento Topologico

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000005;

int ge[MAX];
vector <int> adlist[MAX];
vector <int> palos;
queue <int> cola;

int main()
{
    while(true)
    {
        int n, r;
        cin >> n >> r;

        if(n == 0)
            break;

        //fill(ge, ge + n + 1, 0);
        for(int i = 1; i <= n; i++){
            adlist[i].clear();
            ge[i] = 0;
        }

        palos.clear();

        for(int i = 0; i < r; i++)
        {
            int r1, r2;
            cin >> r1 >> r2;
            ge[r2]++;
            adlist[r1].push_back(r2);
        }

        for(int i = 1; i <= n; i++)
            if(ge[i] == 0)
                cola.push(i);

        while( !cola.empty() )
        {
            int p = cola.front();
            cola.pop();

            palos.push_back(p);

            for(int i = 0; i < adlist[p].size(); i++)
            {
                ge[adlist[p][i]]--;
                if(ge[adlist[p][i]] == 0)
                    cola.push(adlist[p][i]);
            }
        }
        if(palos.size() != n)
            cout << "IMPOSSIBLE" << endl;
        else
            for(int i = 0; i < palos.size(); i++)
                cout << palos[i] << endl;
    }
    return 0;
}


