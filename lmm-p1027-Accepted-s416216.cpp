#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

const int MAXN = 1000;
const int INF = (1 << 30);

using namespace std;
typedef pair<double, int>par;

struct tri{
    double dis, tem;
    int  nod;
    tri(double a = 0, double b = 0, int c = 0)
    {
        tem = a;
        dis = b;
        nod = c;
    }
    bool operator < (const tri &R)const
    {
        if (R.tem != tem)
            return R.tem > tem;
        return R.dis > dis;
    }
};

int N, M, a, b;
int wayf[MAXN];
double dist[MAXN], Temp[MAXN];
vector <tri> adlist[MAXN];

priority_queue <tri> dQ;
priority_queue <par, vector<par>, greater<par> > tQ;

void dijkstra1()
{
    tQ.push(par(0, a));
    fill (Temp + 1, Temp + N + 1, INF);
    Temp[a] = 0;
    while (!tQ.empty())
    {
        double tem = tQ.top().first;
        int nod = tQ.top().second;
        tQ.pop();

        for(int i =  0; i < (int)adlist[nod].size(); i++)
        {
            int newn = adlist[nod][i].nod;
            double mtemp = max(tem , adlist[nod][i].tem);
            if (Temp[newn] > mtemp)
            {
                Temp[newn] = mtemp;
                tQ.push(par(mtemp, newn));
            }
        }
    }
}

void dijkstra2()
{
    dQ.push(tri(0,0,a));
    fill (dist + 1, dist + N + 1, INF);
    dist[a] = 0;
    while (!dQ.empty())
    {
        double tem = dQ.top().tem;
        double dis = dQ.top().dis;
        int nod = dQ.top().nod;
        dQ.pop();

        for (int i = 0; i < (int)adlist[nod].size(); i++)
        {
            double newt = max(adlist[nod][i].tem, tem);
            double newd = dis + adlist[nod][i].dis;
            int newn = adlist[nod][i].nod;

            if (dist[newn] > newd && newt <= Temp[b])
            {
                wayf[newn] = nod;
                dist[newn] = newd;
                dQ.push(tri(newt, newd, newn));
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
        for(int i = 1; i <= N; i++)
            adlist[i].clear();

        fill (wayf + 1, wayf + N + 1, 0);

        for(int i = 1; i <= M; i++)
        {
            int a, b;
            double t, d;
            scanf ("%d %d %lf %lf", &a, &b, &t, &d);
            adlist[a].push_back(tri(t,d,b));
            adlist[b].push_back(tri(t,d,a));
        }
        dijkstra1();
        dijkstra2();

        print (a, b);
        printf ("%.1lf %.1lf\n", dist[b], Temp[b]);
    }

    return 0;
}
