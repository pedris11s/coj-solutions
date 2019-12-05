#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i, a, b) for(int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define SD(n) scanf("%d",&n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define zero(n) memset(n,0,sizeof(n))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define MAXN 1000005
typedef complex<double> P;
typedef vector<P> Pol;
#define X real()
#define Y imag()
const double EPS = 1e-8;

bool cmp(const P a, const P b)
{
    return (a.X!=b.X) ? (a.X<b.X) : (a.Y < b.Y);
}
double cross(P a, P b)
{
    return a.X*b.Y - a.Y*b.X;
}

int ccw(P a, P b, P c)
{
    double d = cross(b-a,c-a);
    if(d>EPS)return +1;
    if(d<EPS)return -1;
    return 0;
}
Pol convexHull(Pol ps)
{
    int t,i,n = ps.size(), k = 0;
    if(n<3) return ps;
    sort(ps.begin(), ps.end(), cmp);
    Pol ch(2*n);
    for(i = 0; i < n; ch[k++] = ps[i++])
        while(k >= 2 && ccw(ch[k - 2], ch[k- 1], ps[i]) <= 0)--k;
    for(i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
        while(k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)--k;
    ch.resize(k - 1);
    return ch;
}

pair <P, P> closestPair(Pol p)
{
    int i,n = p.size(), s= 0, t =1, m = 2;
    vector <int> S(n); S[0] = 0, S[1] = 1;
    sort(p.begin(), p.end(), cmp);
    double d = norm(p[s] - p[t]);
    for(i = 2; i < n; S[m++] = i++)
        FOR(j, m){
            if(norm(p[S[j]] - p[i]) < d)
                d = norm(p[s = S[j]] - p[t = i]);
            if(p[S[j]].X < p[i].X-d)
                S[j--] = S[--m];
        }
    return mp(p[s], p[t]);
}
double distancia(P a, P b)
{
    return sqrt((a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y));
}
int t, n;
double a,b;
Pol pol;
int main()
{
    SD(t);
    while(t--)
    {
        SD(n);
        pol.clear();
        FOR(i, n)
        {
            scanf("%lf%lf", &a, &b);
            pol.pb(P(a,b));
        }
        pair<P,P> aux = closestPair(pol);
        int sol = distancia(aux.first, aux.second);
        printf("%d\n", sol);
    }
    return 0;
}
