#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 2001;

int V, A;
vector <int> Adlist[MAXN];
bool mk[MAXN];

int bfs(int nodo)
{
    fill(mk + 1, mk + V + 1, false);

    queue <int> cola;
    cola.push(nodo);
    mk[nodo] = true;
    int cont = 0;
    while(!cola.empty())
    {
        int nod = cola.front();
        cola.pop();

        cont++;

        for(int i = 0; i < Adlist[nod].size(); i++)
        {
            int nn = Adlist[nod][i];
            if(mk[nn])continue;

            cola.push(nn);
            mk[nn] = true;
        }
    }
    return cont;

}

bool sol()
{
    for(int i = 1; i <= V; i++)
    {
        int x = bfs(i);
        if(x != V)
            return false;
    }
    return true;
}

int main()
{
    while(true)
    {
        cin >> V >> A;
        if(V == 0 && A == 0)
           break;

        for(int i = 1; i <= V; i++)
            Adlist[i].clear();

        for(int i = 1; i <= A; i++){
            int a,b, d;
            cin >> a >> b >> d;
            Adlist[a].push_back(b);
            if(d == 2)
                Adlist[b].push_back(a);

        }
        if(sol())
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
