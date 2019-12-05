#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5001;

int A[MAXN], B[MAXN], C[MAXN], D[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, a, b, c, d;
    while(true){
        cin >> n >> a >> b >> c >> d;
        if(n + a + b + c + d == 0)break;

        for(int i = 0; i < a; i++)
            cin >> A[i];
        for(int i = 0; i < b; i++)
            cin >> B[i];
        for(int i = 0; i < c; i++)
            cin >> C[i];
        for(int i = 0; i < d; i++)
            cin >> D[i];

        vector <int> V;
        for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                V.push_back(A[i] + B[j]);

        sort(V.begin(), V.end());
        long long sol = 0;
        for(int i = 0; i < c; i++)
            for(int j = 0; j < d; j++)
            {
                int sum = C[i] + D[j];
                int p = upper_bound(V.begin(), V.end(), n - sum) - V.begin();
                sol += p;
            }
        cout << sol << "\n";
    }

    return 0;
}
