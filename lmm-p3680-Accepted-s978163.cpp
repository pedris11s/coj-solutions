#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 7;

LL A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int N, M;
        cin >> N >> M;
        for(int i = 0; i < N; i++)
            cin >> A[i];

        sort(A, A + N);
        LL sum = 0, i = 0, sol = 0;
        for(int i = 0; i < N; i++)
            if(sum + A[i] <= M){
                sum += A[i];
                sol++;
            }
            else
                break;
        cout << sol << "\n";
    }

    return 0;
}
