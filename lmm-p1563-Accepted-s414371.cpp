#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1001;

struct trio{
    int nodo, d, s;
    trio(int a = 0, int b = 0, int c = 0)
    {
        nodo = a, d = b, s = c;
    }

    bool operator < (const trio &p)const
    {
        if(s != p.s)
            return s > p.s;
        return d > p.d;
    }
};

int N, M, B, E;
int dist[MAXN], sunimp[MAXN];
vector <trio> adlist[MAXN];
priority_queue <trio> cola;

int Dijkstra()
{
    fill(dist, dist + N + 1, 1 << 30);
    fill(sunimp, sunimp + N + 1, 1 << 30);

    dist[B] = sunimp[B] = 0;

    cola.push(trio(B, 0, 0));
    while(!cola.empty())
    {
        int actual = cola.top().nodo;
        int d = cola.top().d;
        int s = cola.top().s;
        cola.pop();

        for(int i = 0; i < adlist[actual].size(); i++)
        {
            int nn = adlist[actual][i].nodo;
            int nsun = s + adlist[actual][i].s;
            int ndist = d + adlist[actual][i].d;

            if(nsun < sunimp[nn])
            {
                cola.push(trio(nn, ndist, nsun));
                dist[nn] = ndist;
                sunimp[nn] = nsun;
            }
            if(nsun == sunimp[nn] && ndist < dist[nn])
            {
                cola.push(trio(nn, ndist, nsun));
                dist[nn] = ndist;
                sunimp[nn] = nsun;
            }
        }
    }
    cout << dist[E] << ' ' << sunimp[E] << endl;
}


int main()
{
    cin >> N >> M >> B >> E;
    B++, E++;
    for(int i = 0; i < M; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adlist[a + 1].push_back(trio(b + 1, c, c - d));
        adlist[b + 1].push_back(trio(a + 1, c, c - d));
    }
    Dijkstra();

    return 0;
}
