#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1001;
const int INF = (1 << 30);

typedef pair <double, int> par;

struct tri{
    double cos;
    int  maf, nod;
    tri (double a = 0,int b = 0, int c = 0)
    {
        cos = a;
        maf = b;
        nod = c;
    }
    bool operator < (const tri &R)const
    {
        if (R.cos != cos)
            return R.cos > cos;
        return R.maf > maf;
    }
};

int N, M, C, a, b, MF[MAXN], mafia[MAXN], wayf[MAXN];;
double dist[MAXN];
vector <par> adlist[MAXN];
priority_queue<tri> dQ;
priority_queue<par, vector<par>, greater<par> >mQ;


void dijkstra1()
{
    fill (mafia + 1, mafia + N + 1, INF);

    mafia[a] = MF[a];
    mQ.push(par(MF[a], a));
    while (!mQ.empty())
    {
        int cos = mQ.top().first;
        int nod = mQ.top().second;
        mQ.pop();

        for (int i =  0; i < (int)adlist[nod].size(); i++)
        {
            int next = adlist[nod][i].second;
            int newc = cos + MF[next];
            if (mafia[next] > newc)
            {
                mafia[next] = newc;
                mQ.push(par(newc, next));
            }
        }
    }
}

void dijkstra2()
{
    dQ.push(tri(0,MF[a],a));
    fill (dist + 1, dist + N + 1, INF);
    dist[a] = MF[a];
    while (!dQ.empty())
    {
        double cos = dQ.top().cos;
        int maf = dQ.top().maf;
        int nod = dQ.top().nod;
        dQ.pop();

        for(int i = 0; i < (int)adlist[nod].size(); i++)
        {
            double newc = adlist[nod][i].first + cos;
            int newn = adlist[nod][i].second;
            int newm = MF[newn] + maf;

            if(dist[newn] > newc && newm <= mafia[b])
            {
                wayf[newn] = nod;
                dist[newn] = newc;
                dQ.push(tri(newc, newm, newn));
            }
        }
    }
}

void print(int a, int b)
{
      vector <int> sol;
      int bb = b;
      while(a != bb)
      {
          sol.push_back(bb);
          bb = wayf[bb];
      }
    sol.push_back(a);
    for(int i = sol.size() - 1; i > -1; i--)
        if(i != 0)
            cout << sol[i] << " " ;
        else
            cout << sol[i] << "\n";
}

int main(){

    while (scanf ("%d %d %d %d", &N, &M, &a, &b) != EOF)
    {
        for (int i = 1; i <= N; i++)
            adlist[i].clear();

        fill (wayf + 1, wayf + N + 1, 0);
        fill (MF + 1, MF + N + 1, 0);

        for(int i = 1; i <= M; i++)
        {
            int a, b;
            double c;
            scanf ("%d %d %lf", &a, &b, &c);
            adlist[a].push_back(par(c, b));
            adlist[b].push_back(par(c, a));
        }

        scanf ("%d", &C);
        for (int i = 1; i <= C; i++)
        {
            int aa;
            scanf ("%d", &aa);
            MF[aa] = 1;
        }

        dijkstra1();
        dijkstra2();

        print (a, b);
        printf ("%d %.2lf\n", mafia[b], dist[b]);
    }

    return 0;
}
