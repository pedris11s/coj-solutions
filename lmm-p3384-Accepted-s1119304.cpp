#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 2007;

typedef pair <int, int> par;

int N, M, R, E;
bool mk[MAXN];
bool aris[MAXN][MAXN];
vector <int> adlist[MAXN];

LL bfs(int nod){

    queue <int> cola;
    cola.push(nod);
    mk[nod] = true;

    LL cn = 0, ca = 0;
    while(!cola.empty()){
        int nodo = cola.front();
        cola.pop();
        cn++;
        for(int i = 0; i < adlist[nodo].size(); i++){
            int nn = adlist[nodo][i];

            if(!aris[nodo][nn])
                ca++;
            aris[nodo][nn] = aris[nn][nodo] = true;

            if(mk[nn])continue;

            cola.push(nn);
            mk[nn] = true;



        }
    }
    LL v1 = (((cn * (cn - 1)) / 2) - ca) * R;
    LL v2 = cn * E;
    return min(v1, v2);
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> M >> R >> E;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }
    LL sol = 0;
    for(int i = 1; i <= N; i++)
        if(!mk[i]){
            sol += bfs(i);
        }
    cout << sol << '\n';


    return 0;
}
