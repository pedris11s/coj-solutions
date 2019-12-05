#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int N, M, root;
int tiempo[MAXN];
vector <int> adlist[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adlist[a].push_back(b);
    }
    cin >> root;

    queue <int> cola;
    cola.push(root);

    int sol = 0;
    while(!cola.empty()){
        int nodo = cola.front();
        cola.pop();

        int val = tiempo[nodo] + adlist[nodo].size();
        sol = max(sol, val);
        for(int i = 0; i < adlist[nodo].size(); i++){
            int nn = adlist[nodo][i];
            tiempo[nn] = val;
            cola.push(nn);
        }
    }
    cout << sol << "\n";
    vector <int> lista;
    for(int i = 1; i <= N; i++)
        if(tiempo[i] == sol)
            lista.push_back(i);

    cout << lista[0];
    for(int i = 1; i < lista.size(); i++)
        cout << " " << lista[i];
    cout << "\n";


    return 0;
}
