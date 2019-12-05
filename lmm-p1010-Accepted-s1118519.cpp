#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define oo 100000000

struct node {
    int from, to, d;
} links[10005];

int t, n, v, sol1, sol2, ruta[105], p[105], mst[105];

bool cmp(node a, node b) {
    return a.d < b.d;
}

int find_set(int u) {
  return (p[u] < 0) ? u : p[u] = find_set(p[u]);
}

void merge(int u, int v) {
    u = find_set(u); v = find_set(v);
    if (-p[u] < -p[v])
        swap(u, v);
    p[u] += p[v];
    p[v] = u;
}

int kruskal(int jump) {
    memset(p, -1, sizeof(p));
    memset(ruta, -1, sizeof(ruta));
    int size = 0;
    int cost = 0;
    for(int i = 0; i < v && size != n - 1; i++) {
        if(i == jump)continue;
        if(find_set(links[i].from) != find_set(links[i].to)) {
            merge(links[i].from, links[i].to);
            cost += links[i].d;
            ruta[size++] = i;
        }
    }
    
    if(size == n - 1)return cost;
    else return oo;
}

bool match() {
    for(int i = 0; i < n - 1; i++)
        if(mst[i] != ruta[i])
            return false;
    return true;
}

main() {
    cin >> t;
    while(t--) {
        memset(mst, -1, sizeof(mst));
        cin >> n >> v;
        for(int i = 0; i < v; i++)
            cin >> links[i].from >> links[i].to >> links[i].d;
        sort(links, links + v, cmp);
        sol1 = kruskal(-1);
        for(int i = 0; i < n; i++)mst[i] = ruta[i];
        sol2 = oo;
        for(int i = 0; i < n - 1; i++) {
            int temp = kruskal(mst[i]);
            if(sol2 > temp && !match())
                sol2 = temp;
        }
        cout << sol1 << ' ' << ((sol2 == oo) ? sol1 : sol2) << '\n';
    }
}