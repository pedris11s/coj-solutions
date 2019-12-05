#include <bits/stdc++.h>

using namespace std;

const int MAXN = 507;

int N, cApt = 1;
int Phone[MAXN];
int B[MAXN];
int PhoApt[MAXN];
vector <int> adlist[MAXN];
vector <int> NodosPend[MAXN];

void bfs(int nod)
{
    queue <int> cola;
    cola.push(nod);
    B[nod] = cApt;

    int num;
    if(Phone[nod] != 0)
        num = Phone[nod];

    vector <int> nodos;
    nodos.push_back(nod);


    while(!cola.empty())
    {
        int nodo = cola.front();
        cola.pop();
        for(int i = 0; i < adlist[nodo].size(); i++)
        {
            int nn = adlist[nodo][i];
            if(B[nn] != 0)continue;

            if(Phone[nn] != 0)
                num = Phone[nn];

            cola.push(nn);
            B[nn] = B[nodo];
            nodos.push_back(nn);
        }
    }
    for(int i = 0; i < nodos.size(); i++)
        Phone[nodos[i]] = num;
}

int main()
{
    //freopen(".in", "r", stdin);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> Phone[i];

    int a, b;
    while(cin >> a >> b)
    {
        //cout << a << ' ' << b << endl;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }
    for(int i = 1;i <= N; i++)
        if(B[i] == 0)
        {
            bfs(i);
            cApt++;
        }
    for(int i = 1; i <= N; i++)
        cout << Phone[i] << endl;

    return 0;
}
