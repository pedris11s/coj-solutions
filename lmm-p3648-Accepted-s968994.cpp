#include <bits/stdc++.h>

using namespace std;
long long n, l, a, cas, sol, C[1005], A[1005], B[1005], ta;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> cas;
    while (cas--){
           cin >> n >> l >> a;
           for (int i = 1; i <= n; i++){
                cin >> C[i] >> A[i] >> B[i];
                if (i > 1){
                    A[i] = min (A[i-1], A[i]);
                    B[i] = min (B[i-1], B[i]);
                }
           }

           ta = 0ll;
           for (int i = 1; i <= n; i++){
                sol += A[i]*l*C[i];
                if (C[i]*a < ta){
                    ta -= C[i]*a;
                    continue;
                }
                sol += ((C[i]*a-ta)/80ll)*B[i];
                if ((C[i]*a-ta)%80ll > 0ll) {
                    sol += B[i];
                    ta = 80ll-(C[i]*a-ta)%80ll;
                }
                else ta = 0ll;
           }

           cout << sol << endl;
           sol = 0ll;
    }

    return 0;
}
