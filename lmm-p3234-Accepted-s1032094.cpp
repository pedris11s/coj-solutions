#include <cstdio>

using namespace std;
int n, m, a, sol;
int main(){

    while (scanf ("%d%d", &m, &n)&&(n || m)){
           for (int i = 1; i <= n; i++){
                scanf ("%d", &a);
                if (a <= m){
                    m-=a;
                    sol++;
                }
           }
           printf ("%d %d\n", sol, m); sol = 0;
    }

    return 0;
}
