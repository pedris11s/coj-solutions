//by pter
//algorithm: floyd_warshall
 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
 
const int MAXN = 101;
const int INF = 19999990;
const int MAXQ = 10001;
 
typedef pair <int, int> pii;
 
#define x first
#define y second
 
int d[MAXN][MAXN];
pii query[MAXQ];
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        //inicializando infinito
        for(int i = 0; i < MAXN; i++)
            for(int j = 0; j < MAXN; j++)
                d[i][j] = INF;
 
        //leyendo los datos
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (d[a][b] > c)
                 d[a][b] = d[b][a] = c;
        }
        int q;
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            int c1, c2;
            cin >> c1 >> c2;
            query[i] = make_pair(c1, c2);
        }
 
        //inicializando el camino de un nodo a el mismo con cero
        for(int i = 1; i <= n; i++)
            d[i][i] = 0;
 
        //generando todos los caminos minimos :: floyd_warshall
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];
 
        //respondiendo las querys
        for(int i = 0; i < q; i++)
        {
            int dist = d[query[i].x][query[i].y];
            if(dist == INF)
                cout << "-1" << endl;
            else
                cout << dist << endl;
        }
        if (t > 0)
	        cout << endl;
    }
 
    return 0;
} 
