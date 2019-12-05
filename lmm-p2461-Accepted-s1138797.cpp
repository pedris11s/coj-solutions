#include <bits/stdc++.h>

using namespace std;
#define fo(i,n) for(int i =0;i<n;i++)
#define zero(x) memset(x,0,sizeof(x))
#define mone(x) memset(x,-1,sizeof(x))


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
