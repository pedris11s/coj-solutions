#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 507;

int N, Q;
int V[MAXN];
int mcd[MAXN];
bool mk[MAXN];
vector <int> adlist[MAXN];

int bfs(int ini, int fin){

    fill(mk, mk + N, false);
    for(int i = 0; i < N; i++)
        mcd[i] = V[i];

    queue <int> cola;

    cola.push(ini);
    mk[ini] = true;

    int sol;

    int last = -1;
    while(!cola.empty()){
        int nod = cola.front();
        cola.pop();

        if(nod == fin)
            return mcd[fin];

        for(int i = 0; i < adlist[nod].size(); i++)
        {
            int nn = adlist[nod][i];
            if(mk[nn])continue;

            cola.push(nn);
            mk[nn] = true;
            mcd[nn] = __gcd(mcd[nn], mcd[nod]);
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in", "r", stdin);


    while(cin >> N){
        for(int i = 0; i < N; i++)
            adlist[i].clear();

        for(int i = 0; i < N; i++)
            cin >> V[i];

        for(int i = 0; i < N - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
            adlist[b].push_back(a);
        }

        cin >> Q;
        while(Q--){
            int a, b, c;
            cin >> a >> b >> c;
            if(a == 1){
                cout << bfs(b, c) << "\n";
            }else{
                V[b] = c;
            }
        }
    }

    return 0;
}
