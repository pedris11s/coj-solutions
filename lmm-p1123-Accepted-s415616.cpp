#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;
int n, c;
long long A[2000];
map<long long,bool>M;

int main()
{

    A[1] = 1, c = 1;
    for (int i = 1; c <= 1600; i++){
         if (!M[A[i]*2]){
             M[A[i]*2]=1;
             A[++c] = A[i]*2;
         }
         if (!M[A[i]*3]){
             M[A[i]*3]=1;
             A[++c] = A[i]*3;
         }
         if (!M[A[i]*5]){
             M[A[i]*5]=1;
             A[++c] = A[i]*5;
         }
         sort (A+i+1, A+c+1);
    }

    sort (A+1, A+c+1);

    while (1){
           scanf ("%d", &n);
           if (n==0)break;
           printf ("%lld\n", A[n]);
    }

    return 0;
}
