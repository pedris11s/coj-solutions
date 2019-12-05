#include <bits/stdc++.h>

using namespace std;

int padres[2048];

void init(int n) {
    for(int i=0;i<n;i++) {
        padres[i] = i;
    }
    return;
}

int find(int t) {
    if(padres[t] == t) {
        return t;
    }
    padres[t] = find(padres[t]);
    return padres[t];
}

void join(int a, int b) {
    padres[find(a)] = find(b);
}

vector<pair<int,pair<int,int> > > roads;

void kruskal(int n, int &res, int start, int end, int i) {
    init(n);
    int mn = roads[i].first;
    while(i < roads.size() && find(start) != find(end)) {
        join(roads[i].second.first,roads[i].second.second);
        i++;
    }
    if(find(start) == find(end)) {
        res = min(res,roads[i-1].first-mn);
    }
    return;
}

int main() {
    int t=1;
    //cin >> t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(t--) {
        int n, r, start, end;
        cin >> n >> r >> start >> end;
        roads.resize(r);
        for(int i=0;i<r;i++) {
            cin >> roads[i].second.first >> roads[i].second.second >> roads[i].first;
        }
        sort(roads.begin(),roads.end());
        int res = 2000000001;
        for(int i=0;i<r;i++) {
            kruskal(n,res,start,end,i);
        }
        if(res == 2000000001) {
            cout << "NO PATH\n";
        } else {
            cout << res << '\n';
        }
    }
}