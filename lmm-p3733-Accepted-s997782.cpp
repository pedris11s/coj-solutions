#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d", &n,&m)
#define SS(n) scanf("%s", n)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i,a,b) for(int i = a; i < b; i++)
#define FORR(i, n) for(int i = n; i >= 0; i--)
#define zero(n) memset(n,0,sizeof(n))
#define mone(n) memset(n,-1,sizeof(n))
//typedef complex<double> P;
typedef pair <int, int> par;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

const int MAXN = 100;
const int MAXE = 100005;

int F, C, CONT = 1, Ari;
vector <par> islas[MAXE];
char M[MAXN][MAXN];
int I[MAXN][MAXN];
int P[MAXE];

int find(int x){
    if(P[x] == x)
        return x;
    return P[x] = find(P[x]);
}

struct trio{
    int A, B, C;
    trio(){}
    trio(int A, int B, int C): A(A),B(B),C(C){}
    bool operator < (const trio &z) const {
        return C < z.C;
    }

}Edges[MAXE];

int dist(par a, par b){
    return abs(a.first - b.first) + abs(a.second - b.second) - 1;
}

void bfs(int x, int y){
    queue <par> cola;
    cola.push(par(x, y));

    M[x][y] = '.';
    I[x][y] = CONT;

    while(!cola.empty()){
        par actual = cola.front();
        cola.pop();

        islas[CONT].pb(actual);

        for(int i = 0; i < 4; i++){
            int nx = actual.first + dx[i];
            int ny = actual.second + dy[i];

            if(nx > F || nx < 1 || ny > C || ny < 1)continue;
            if(M[nx][ny] == '.')continue;

            M[nx][ny] = '.';
            I[nx][ny] = CONT;
            cola.push(par(nx, ny));
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        memset(I, 0, sizeof(I));

        CONT = 1, Ari = 0;

        cin >> F >> C;
        for(int i = 1; i <= F; i++)
            for(int j = 1; j <= C; j++)
                cin >> M[i][j];

        for(int i = 1; i <= F; i++)
            for(int j = 1; j <= C; j++)
                if(M[i][j] == 'X'){
                    bfs(i, j);
                    CONT++;
                }

        for(int i = 1; i < CONT - 1; i++){
            for(int j = i + 1; j < CONT; j++)
            {
                int d = (1 << 30);
                for(int k = 0; k < islas[i].size(); k++)
                    for(int l = 0; l < islas[j].size(); l++)
                        d = min(d, dist(islas[i][k], islas[j][l]));
                Edges[Ari++] = trio(i, j, d);
            }

        }
        for(int i = 1; i <= CONT; i++)
            P[i] = i;



        sort(Edges, Edges + Ari);
        //for(int i = 0; i < Ari; i++){
        //   cout << Edges[i].A << ' ' << Edges[i].B << ' ' << Edges[i].C << "\n";
        //}

        int sol = 0;
        for(int i = 0; i < Ari; i++)
        {
            int x = find(Edges[i].A);
            int y = find(Edges[i].B);
            if(x != y)
            {
                P[x] = y;
                sol += Edges[i].C;
            }
        }



        /*for(int i = 1; i <= F; i++){
            for(int j = 1; j <= C; j++)
                cout << I[i][j];
            cout << endl;
        }*/
        //cout << "ESTA ES LA SOL >> " << sol << "\n";
        cout << sol << "\n";
        for(int i = 1; i <= CONT; i++)
            islas[i].clear();
    }


    return 0;
}
