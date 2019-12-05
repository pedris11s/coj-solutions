#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

typedef pair <int, int> par;

int N, M, R, E;
bool mk[MAXN];
int costo[MAXN];
vector <int> adlist[MAXN];

par bfs(int ini){

    fill(costo, costo + N + 1, 0);
    fill(mk, mk + N + 1, false);

    int nodo, maxi = -1;
    queue <int> cola;
    cola.push(ini);
    mk[ini] = true;
    costo[ini] = 0;


    while(!cola.empty()){
        int nod = cola.front();
        cola.pop();

        if(costo[nod] > maxi){
            maxi = costo[nod];
            nodo = nod;
        }

        for(int i = 0; i < adlist[nod].size(); i++){
            int nn = adlist[nod][i];
            if(mk[nn])continue;

            cola.push(nn);
            mk[nn] = true;
            costo[nn] = costo[nod] + 1;
        }
        //cout << "sali\n" ;
    }
    return par(nodo, maxi);
}


int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--){

        cin >> N;
        for(int i = 0; i < N - 1; i++){
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
            adlist[b].push_back(a);
        }


        par a = bfs(1);
        //cout << a.first << " " << a.second << "\n";
        par b = bfs(a.first);

        int sol = b.second + 1;
        cout << sol << '\n';

        for(int i = 0; i <= N; i++)
            adlist[i].clear();
    }
    return 0;
}
