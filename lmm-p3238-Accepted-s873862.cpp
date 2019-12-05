#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int N, A[MAXN], sol, x=0;

int main()
{
    int t;
    scanf("%d", &t);
    
    while(t--){

        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
            scanf("%d", &x);
            sol = max(sol, abs(x-i));
        }

           printf("%d\n", sol);
           sol = 0;
    }


    return 0;
}
