#include <bits/stdc++.h>

using namespace std;
int n;
int  S[100005], T[100005];
struct par{
       int p;
       long long v;
       bool operator <(const par &R)const{
            return v < R.v;
       }
}A[100005];

bool update (int p){
     for (int i = p; i <= n; i += (i & -i))
          T[i]++;
}

int query (int p){
     int can = 0;
     for (int i = p; i >= 1; i -= (i & -i))
          can += T[i];
     return ++can;
}

int main(){

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%lld", &A[i].v);
         A[i].p = i;
    }

    sort (A+1,A+n+1);

    for (int i = 1; i <= n; i++){
         S[A[i].p] = query(A[i].p);
         update (A[i].p);
    }

    for (int i = 1; i <= n; i++)
         printf ("%d\n", S[i]);

    return 0;
}
