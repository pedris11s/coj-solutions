#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 7;

typedef pair <int, int> par;

int N, K, A[MAXN], Ord[MAXN];
vector <int> adlist[MAXN];
bool mk[MAXN];


void top_sort(int nod)
{
    mk[nod] = true;
    int lon = adlist[nod].size() - 1;
    for(int i = 0; i <= lon; i++)
    {
        int nn = adlist[nod][i];
        if(!mk[nn])
            top_sort(nn);
    }

    Ord[K--] = nod;
    return;
}

void bfs(int nodo)
{
    queue <int> cola;
    cola.push(nodo);
    mk[nodo] = true;

    while(!cola.empty())
    {
        int nn = cola.front();
        cola.pop();

        for(int i = 0; i < adlist[nn].size(); i++)
        {
            int nod = adlist[nn][i];
            if(mk[nod])continue;

            cola.push(nod);
            mk[nod] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);


    int t;
    cin >> t;
    while(t--)
    {
        cin >> N;
        for(int i = 0; i <= N; i++)
            adlist[i].clear();
        fill(mk, mk + N + 1, false);

        for(int i = 1; i <= N; i++)
        {
            cin >> A[i];
            adlist[A[i]].push_back(i);
        }
        K = N;
        for(int i = 1; i <= N; i++)
            if(!mk[i])
                top_sort(i);

        fill(mk, mk + N + 1, false);
        int sol = 0;
        for(int i = 1; i <= N; i++)
            if(!mk[Ord[i]]){
                bfs(Ord[i]);
                sol++;
            }
        cout << sol << "\n";

    }





    return 0;
}
