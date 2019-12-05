#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 200010;
const int MAX_LOG = 20;

typedef pair <int, int> pii;

int N, K, Raiz;
int L[MAXN], mLevel[MAXN];
int LCA[MAXN][MAX_LOG];
int C[MAXN][MAX_LOG];
queue <int> cola;
vector <pii> adlist[MAXN];
vector <int> partido[MAXN / 2];

void Build_LCA()
{
    L[Raiz] = 1;
    cola.push(Raiz);
    while(!cola.empty())
    {
        int actual = cola.front();
        cola.pop();

        for(int i = 0; i < adlist[actual].size(); i++)
        {
            int nn = adlist[actual][i].first;
            int costo = adlist[actual][i].second;
            if(L[nn])
                continue;

            L[nn] = L[actual] + 1;
            LCA[nn][0] = actual;
            C[nn][0] = costo;
            cola.push(nn);

            int maxlg = (int)log2(L[nn]);
            for(int j = 1; j <= maxlg; j++)
                if(LCA[nn][j - 1])
                {
                    LCA[nn][j] = LCA[LCA[nn][j - 1]][j - 1];
                    C[nn][j] = C[nn][j - 1] + C[LCA[nn][j - 1]][j - 1];
                }
        }
    }
}

int Dist(int j, int k)
{
    if(L[j] < L[k])
        swap(j, k);

    int cost = 0;
    int maxlg = (int)log2(L[j]);
    for(int i = maxlg; i > -1; i--)
        if(L[j] - (1 << i) >= L[k] && LCA[j][i])
            cost += C[j][i], j = LCA[j][i];

    if(j == k)
        return cost;

    maxlg = (int)log2(L[j]);
    for(int i = maxlg; i >= 0; i--)
        if( LCA[j][i] && LCA[j][i] != LCA[k][i])
        {
            cost += C[j][i] + C[k][i];
            j = LCA[j][i];
            k = LCA[k][i];
        }

    cost += C[j][0] + C[k][0];
    return cost;
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        partido[a].push_back(i);
        if(b != 0)
        {
            adlist[i].push_back(pii(b, 1));
            adlist[b].push_back(pii(i, 1));
        }
        else
            Raiz = i;
    }
    Build_LCA();
    for(int i = 1; i <= K; i++)
    {
        int nodo;
        int max = 0;
        for(int j = 0; j < partido[i].size(); j++)
            if(L[partido[i][j]] > max)
            {
                max = L[partido[i][j]];
                nodo = partido[i][j];
            }
        mLevel[i] = nodo;
        //cout << nodo << endl;
    }

    for(int i = 1; i <= K; i++)
    {
        int max = 0;
        for(int j = 0; j < partido[i].size(); j++)
        {
            int d = Dist(mLevel[i], partido[i][j]);
            if(d > max)
                max = d;
        }
        cout << max << endl;
    }

    return 0;
}
