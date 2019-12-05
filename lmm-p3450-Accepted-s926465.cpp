#include <bits/stdc++.h>

using namespace std;

#define val first
#define sum second.first
#define id second.second.first
#define type second.second.second

const int MAXN = 1007;

typedef pair <int, int> par;
typedef pair <int, par> trio;
typedef pair <int, trio> cuad;

int N, A[MAXN], B[MAXN];
priority_queue <cuad, vector <cuad>, greater <cuad> > cola;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> A[i] >> B[i];
            cola.push(cuad(A[i], trio(1, par(i, 1))));
        }

        int sol = 0, cant = 0;
        while(!cola.empty()){

            int x = cola.top().val;
            int iD = cola.top().id;
            int s = cola.top().sum;
            int tp = cola.top().type;
            cola.pop();

            if(cant >= x){
                cant += s;
                if(tp == 1){
                    cola.push(cuad(B[iD], trio(2, par(iD, 2))));
                }
            }
            else{
                sol += x - cant;
                cant = x;
                cant += s;
                if(tp == 1)
                    cola.push(cuad(B[iD], trio(2, par(iD, 2))));
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
