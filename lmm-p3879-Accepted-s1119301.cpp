#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 2007;

typedef pair <int, int> par;
typedef pair <int, double> parD;
typedef pair <int, par> trio;

#define x first
#define y second

int N, R[MAXN];
double M[MAXN][MAXN];
par C[MAXN], INI, FIN;
vector <parD> adlist[MAXN];

double dist(par a, par b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double sol = sqrt(dx * dx + dy * dy);
    return sol;
}

double calc(par a, par b, int r){
    double di = dist(a, b);
    if(di < r)
        return min(di,r-di);
    return di - r;
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    //double x = 0.005;
    //printf("%.2lf\n", round(x));


    int a, b, c, d;
    cin >> N >> a >> b >> c >> d;
    INI = par(a, b);
    FIN = par(c, d);
    for(int i = 0; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        C[i] = par(a, b);
        R[i] = c;
    }


    //cout << INI.x << " " << INI.y << endl;
    //cout << FIN.x << " " << FIN.y << endl;

    C[N] = INI; R[N] = 0;
    C[N + 1] = FIN; R[N + 1] = 0;
    N += 2;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            M[i][j] = 2000000000000000000;
    //cout << M[0][0] << endl;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            a = i, b = j;
            if(a == b)
                continue;
            double dst = calc(C[i], C[j], R[i]);
            M[a][b] = dst;
        }

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(M[i][k] + M[k][j] < M[i][j])
                    M[i][j] = M[i][k] + M[k][j];

    double sol = M[N - 2][N - 1];
    printf("%.2lf\n", sol);


    return 0;
}
