#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

struct edge {
    int u,v,r;

    bool operator<(const edge &E) const {
        return r < E.r;}
    };

int main() {
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    vector<edge> E(N);

    map<int,int> P;
    map<int,int> :: iterator it;;
    for(int i =0; i < N; i++) {
        int r,x;
        cin >> x >> r;
        P[x-r] =0, P[x+r] =0;
        E[i].u =x-r;
        E[i].v =x+r;
        E[i].r =r;}

    sort(E.begin(),E.end());
    int V =0;
    for(it = P.begin(); it != P.end(); it++)
    {
        (*it).second = V;
        V++;

    }


    vector< vector<int> > C(V);
    vector<int> isC(V);
    int ans =N;
    for(int i =0; i < V; i++) {
        C[i].push_back(i);
        isC[i] =i;}

    for(int i =0; i < N; i++) {
        int x =isC[P[E[i].u]], y =isC[P[E[i].v]];
        if(x == y) {
            ans++;
            continue;}
        if(C[x].size() > C[y].size()) swap(x,y);
        for(int j =0; j < C[x].size(); j++) {
            isC[C[x][j]] =y;
            C[y].push_back(C[x][j]);}
        }
    cout << ans+1 << "\n";
    return 0;}
