#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int N, M, H;
int HI[MAXN];
queue <int> cola;
vector <int> adlist[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> H >> M;

    fill(HI, HI + N, INT_MAX);

    for(int i = 0; i < H; i++)
    {
        int h;
        cin >> h;
        HI[h] = 0;
        cola.push(h);
    }

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }

    while(!cola.empty())
    {
        int nodo = cola.front();
        cola.pop();

        for(int i = 0; i < adlist[nodo].size(); i++)
        {
            int nn = adlist[nodo][i];
            if(HI[nn] != INT_MAX) continue;

            cola.push(nn);
            HI[nn] = HI[nodo] + 1;
        }
    }
    int nod, max = -1;
    for(int i = 0; i < N; i++)
        if(HI[i] > max){
            max = HI[i];
            nod = i;
        }
    cout << nod << "\n";

	return 0;
}
