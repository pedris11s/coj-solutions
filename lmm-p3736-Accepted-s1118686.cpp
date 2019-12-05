#include <bits/stdc++.h>

using namespace std;

const int oo = 1 << 30;

#define MAX 1004

typedef vector<int> vi;
vi G[MAX];
int ndfs, vdfs[MAX], low[MAX];
bool apoint[MAX];

int cc, ccc;
int Comp[MAX];
int sol, sol2;

void tarjan(int u, int p = -1) {
    vdfs[u] = low[u] = ndfs++;
    for(int i = G[u].size() - 1; i >= 0; i--) {
        int v = G[u][i];
        if(!vdfs[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if((vdfs[u] == 1 && vdfs[v] > 2) || (vdfs[u] != 1 && vdfs[u] <= low[v])) {
                apoint[u] = true;
                sol2++;
            }
            if(vdfs[u] < low[v]) {
                sol++;
            }
        }
        else if(v != p) {
            low[u] = min(low[u], vdfs[v]);
        }
    }
}

int main() {
    int t;
    int n, m, a, b;
    scanf("%d", &t);
    while(t--) {
        sol2 = 0;
        sol = 0;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int comp = 0;
        for(int i = 0; i < n; i++) {
            if(!vdfs[i]) {
                comp++;
                if(comp == 1)
                    tarjan(i);
            }
        }
        if(comp == 1 && sol == 0 && sol2 == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
        for(int i = 0; i < n; i++) {
            G[i].clear();
            apoint[i] = 0;
            vdfs[i] = 0;
            low[i] = 0;
            ndfs = 0;
        }
    }
}
