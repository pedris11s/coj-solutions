#include <bits/stdc++.h>

using namespace std;
#define ll long long
bool pos[100];
ll pot[61];
vector<int> bits;
int ar[1<<21];
int num[100];
int main()
{
    ll n, res=0, r;
    int cant, p=0, tmp, k, cantB=0;
    pot[0]=1;
    for(int i=1;i<61;i++)pot[i]=pot[i-1]*2LL;
    for(int i=(1<<20);i>=0;i--){
        tmp=__builtin_popcount(i);
        ar[i]=tmp;
    }
    while(scanf("%lld", &n)!=EOF){
    for(int i=0;i<65;i++)pos[i]=0;
    bits.clear();
    p=0;res=0;cantB=0;
    while(n>0){
        bits.push_back(n%2);
        n/=2;
    }
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        scanf("%d", &tmp);
        pos[tmp]=true;
        num[p]=tmp;
        p++;
    }
    for(int i=0;i<bits.size();i++){
        if(bits[i] && !pos[i])res+=pot[i];else
        if(bits[i])cantB++;
    }
    for(int mask=(1<<k);mask>=0;mask--){
        if(ar[mask]!=cantB)continue;
        r=0;
        for(int i=0;i<k;i++){
            if(mask&(1<<i))r+=pot[num[i]];
        }
        if((r+res)%7==0){
            break;
        }
    }
    printf("%lld\n", r+res);}
    return 0;
}
