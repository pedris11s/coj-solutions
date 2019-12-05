#include <bits/stdc++.h>

using namespace std;
#define fo(i,n) for(int i =0;i<n;i++)
#define zero(x) memset(x,0,sizeof(x))
#define mone(x) memset(x,-1,sizeof(x))
/*
namespace dinic{

    const int M=1005, oo=(1<<28);
    vector <int> G[M], W[M];
    int F[M][M],n;
    int C[M][M];
    int A[M];
    bool B[M];
    void init(){
        int i;
        fo(i,M)G[i].clear(), W[i].clear();
    }
    void add(int a, int b, int w){
        G[a].push_back(b);
        W[a].push_back(w);
    }

    #define R(s,t) (C[s][t]-F[s][t])
    int augment(int u, int t, int w){
        if (u==t || w==0) return w;
        if (B[u]) return 0;
        B[u]=1;

        int i;
        fo(i,G[u].size()) if (A[G[u][i]] > A[u]){
            int f = augment(G[u][i], t, min(w,R(u,G[u][i])));
            if (f>0){
                F[u][G[u][i]]+=f;
                F[G[u][i]][u]-=f;
                B[u]=0;
                return f;
            }
        }
        return 0;
    }
    int maxFlow(int s, int t){
        int i, j, k;
        zero(F);
        zero(C);

        fo(i,n)fo(j,(int)G[i].size())
            C[i][G[i][j]]+=W[i][j];
        int r=0;

        for (int c=1; c;){
            c=0;
            mone(A);
            A[s]=0;
            queue<int> Q;
            Q.push(s);
            for (int i=n+1; !Q.empty() && A[Q.front()]<i;){
                int j=Q.front();
                Q.pop();
                if (j==t) i=A[j];
                fo(k,(int)G[j].size()) if (R(j,G[j][k])>0 && A[G[j][k]]==-1)
                    Q.push(G[j][k]),A[G[j][k]]=A[j]+1;
            }
            zero(B);
            for (int f=1; f>0;){
                f = augment(s,t,oo);
                if (f==0) break;
                r+=f;
                c=1;
            }
        }
        return r;
    }

}

*/

char cad[100];
int cap[60][60];
int puntos[50];
int oo=(1<<30);
vector<int> V;
int n;
int WS[1000];
int minimumCut()
{

    for (int i=0; i<n; i++) V[i]=i;
    int cut=oo;
    for (int w,v,u,m=n; m>1; m--)
    {
        zero(WS);
        for (int i=0; i<m; i++)
        {
            u=v;
            v=max_element(WS, WS+m)-WS;
            w = WS[v], WS[v]=-1;
            for (int j=0; j<m; j++) if (WS[j]>=0) WS[j]+=cap[V[v]][V[j]];
        }
        for (int i=0; i<m; i++)
        {
            cap[V[i]][V[u]] += cap[V[i]][V[v]];
            cap[V[u]][V[i]] += cap[V[v]][V[i]];
        }
        swap(V[v], V[m-1]);
        cut=min(cut,w);
    }
    return cut;

}

int main()
{


    while(scanf("%s", cad)!=EOF)
    {
        n = strlen(cad);
        V.clear();
        V.resize(n+1);
        zero(cap);

        for (int j=0; j<n; j++)
        {
            cap[0][j] = (cad[j]-'0');
        }
        for (int i=1; i<n; i++)
        {
            scanf("%s", cad);
            for (int j=0; j<n; j++)
            {
                cap[i][j] = (cad[j]-'0');
            }
        }


        printf("%d\n", minimumCut());


        /* dinic::init();
         for (int i=1; i<n; i++){
             for (int j=0; j<i; j++){
                 dinic::add(i,j,mat[i][j]);
                 dinic::add(j,i,mat[i][j]);
             }
         }
         int sol=1000000;
         dinic::n=n;
         for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                 sol=min(sol,dinic::maxFlow(i,j));
             }
         }*/
//        printf("%d\n",sol);
    }





    return 0;
}
