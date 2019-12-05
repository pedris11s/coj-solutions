#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int N, M;
bool mk[MAXN];
vector <int> adlist[MAXN];

int bfs(int nodo)
{
    queue <int> cola;
    cola.push(nodo);
    mk[nodo] = true;
    int sol = 0;
    while(!cola.empty())
    {
        int nod = cola.front();
        cola.pop();

        sol++;

        for(int i = 0; i < adlist[nod].size(); i++)
        {
            int nn = adlist[nod][i];
            if(mk[nn])continue;

            mk[nn] = true;
            cola.push(nn);
        }
    }
    return sol - 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> M;
        fill(mk, mk + N + 1, false);

        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
            adlist[b].push_back(a);
        }

        int sol = 0;
        for(int i = 1; i <= N; i++)
            if(!mk[i])
                sol += bfs(i);
        cout << sol << "\n";
    }
    return 0;
}
