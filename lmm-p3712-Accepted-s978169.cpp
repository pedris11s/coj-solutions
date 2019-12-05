#include <bits/stdc++.h>

using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define fa(i,x,n) for(int i=x;i<n;i++)
#define X first
#define Y second
#define ll long long
#define pb push_back
#define zero(x) memset(x,0,sizeof(x))
#define mone(x) memset(x,-1,sizeof(x))
#define sz(x) x.size()
#define mos(x) cout<<#x<<" = "<<x<<endl
#define MAX 200005
#define mod 1000000007
#define base 107
#define endl '\n'


int n,m;
int mat[400][400];

int gain[400],dp[400][400];

int fun1(int p,int q){
    if(q>=n)return 0;
    if(dp[p][q]!=-1)return dp[p][q];
    dp[p][q] = mat[q][p] + fun1(p,q+2);
    dp[p][q] = max( dp[p][q] , fun1(p,q+1) );
    return dp[p][q];
}

int dp2[400];
int fun2(int q){
    if(q>=m)return 0;
    if(dp2[q]!=-1)return dp2[q];
    dp2[q] = gain[q] + fun2(q + 2);
    dp2[q] = max( dp2[q] , fun2(q+1) );
    return dp2[q];
}

int main(){

    while(scanf("%d%d",&n,&m)!=EOF){
        mone(dp);mone(dp2);
        fo(i,n)fo(j,m)scanf("%d",&mat[i][j]);
        fo(i,m){
            gain[i] = fun1(i,0);
            //cout<<gain[i]<<endl;
        }
        printf("%d\n",fun2(0));
    }
    return 0;
}

