#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i,a,b)  for(int i = a; i < b; i++)
#define zero(n) memset(n, 0, sizeof(n))
#define sz size()
#define mone(n) memset(n, -1, sizeof(n))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MAXN 100005

/*
DINIC MAX FLOW
Este algoritmo baja el tiempo de complejidad a O(N^2 * M);
N -> numero de nodos
M -> numero de aristas
Para cada arista se agrega una con peso 0 en sentido contrario
ejemplo
max_flow::add(a,b,5);
max_flow::add(b,a,0);
Probado: 1560 - Paths for Gladiators COJ
*/

//inicio
namespace dinic{
    const int M=400,oo=(1<<28);
    vector<int> G[M]; //edges
    vector<int> W[M]; //initial flow
    int F[M][M];   //flow
    int C[M][M];   //capacity
    int A[M];
    bool B[M];
    void init(){
        FOR(i,M){
            G[i].clear(),W[i].clear();
        }
    }
    void add(int a,int b,int w){
        G[a].pb(b);
        W[a].pb(w);
    }
    #define R(s,t) (C[s][t]-F[s][t]) //residue
    int augment(int u, int t, int w){
        if (u==t || w==0) return w;
        if (B[u]) return 0;
        B[u] = 1;
        int i;
        FOR(i, G[u].sz) if (A[G[u][i]]>A[u]){
            int f=augment(G[u][i], t, min(w,R(u,G[u][i])));
            if (f>0){
                F[u][G[u][i]]+=f;
                F[G[u][i]][u]-=f;
                B[u]=0;
                return f;
            }
        }
        return 0;
    }
    int maxFlow(int s, int t, int n){
        int i,j,k;
        zero(F);zero(C);
        //n es el numero de nodos
        FOR(i,n)FOR(j,G[i].sz)
            C[i][G[i][j]]+=W[i][j];
        int r=0;
        for(int c=1; c;){
            c=0;
            mone(A);
            A[s]=0;
            queue<int> Q;
            Q.push(s);
            for(int i=n+1; !Q.empty() && A[Q.front()]<i;){
                int j=Q.front();
                Q.pop ();
                if (j==t) i=A[j];
                FOR(k,G[j].sz) if(R(j,G[j][k])>0 && A[G[j][k]]==-1)
                    Q.push(G[j][k]), A[G[j][k]]=A[j]+1;
            }
            zero(B);
            for (int f=1; f>0;){
                f = augment(s, t, oo);
                if (f==0) break;
                //cout<<f<<endl;
                r += f;
                c=1;
            }
        }
        return r;
    }
}
//fin
bool marca[100][100];
string cad;
int cantN = 55;
int main()
{
    while(getline(cin, cad))
    {
        dinic::init();
        int len = cad.size();
        int fila = 1;
        int col = 0;
        int cantNodos = 0;
        /*
        0399 3033 9309 9390
        */
        FOR(i, len)
        {
            if(cad[i]==' ')
            {
                fila++;
                if(cantNodos == 0)cantNodos = col;
                col=0;
            }else{
                if(cad[i]=='0')
                {
                    col++;
                    continue;
                }else{
                    col++;
                    //cout << "adiciona de "<<fila+cantN << " a "<<col <<" " <<cad[i]-48<< endl;
                    dinic::add(fila+cantN,col, cad[i]-48);
                    dinic::add(col, fila+cantN, 0);
                    //dinic::add(col+cantN, fila, cad[i]-48);
                    //cout << "adiciona de "<<col+cantN << " a "<<fila <<" " <<cad[i]-48<< endl;
                    //dinic::add(fila,col+cantN, 0);
                }
            }
        }
        int grande = 1e9;
        for(int i = 1; i <= cantNodos; i++)
        {
            dinic::add(i,i+cantN, grande);
            dinic::add(i+cantN, i, 0);
        }
        int mini = INT_MAX;
        for(int i = 2; i <= cantNodos; i++)
        {
            mini = min(mini, dinic::maxFlow(1, i+cantN, cantNodos+cantN+1));
        }
        printf("%d\n", mini);
    }
    return 0;
}
