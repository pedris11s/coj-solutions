#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAXN = 1000;

#define INF 1000000000

int V, E, Q, C[MAXN];
vector<ii> AdjList[MAXN];

void dijkstra(){

}

int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> V;

        for(int i = 0; i < V; i++)
            AdjList[i].clear();

        for(int i = 0; i < V; i++)
            cin >> C[i];

        cin >> E;
        for(int i = 0; i < E; i++){
            int a, b;
            cin >> a >> b;
            a--, b--;
            int d = (C[b] - C[a]);
            d = d * d * d;
            AdjList[a].push_back(ii(b, d));
        }

        /**-----------------------------------*/
        vi dist(V, INF); dist[0] = 0;
  for (int i = 0; i < V - 1; i++)  // relax all E edges V-1 times, overall O(VE)
    for (int u = 0; u < V; u++)                        // these two loops = O(E)
      for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];        // we can record SP spanning here if needed
        dist[v.first] = min(dist[v.first], dist[u] + v.second);         // relax
      }

  bool hasNegativeCycle = false;
  for (int u = 0; u < V; u++)                          // one more pass to check
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (dist[v.first] > dist[u] + v.second)                 // should be false
        hasNegativeCycle = true;     // but if true, then negative cycle exists!
    }
  /*printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

  if (!hasNegativeCycle)
    for (int i = 0; i < V; i++)
printf("SSSP(%d, %d) = %d\n", 1, i + 1, dist[i]);*/

        /**-----------------------------------*/

        cin >> Q;
        while(Q--){
            int x;
            cin >> x;
            x--;
            if(dist[x] < 3 || dist[x] == INF)
                cout << "?\n";
            else
                cout <</*"locau >> " << */dist[x] << "\n";
        }

    }


    return 0;
}
