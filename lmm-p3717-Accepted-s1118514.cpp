#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int N, A[MAXN];
bool DP[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    vector <int> sol; sol.push_back(N);

    DP[N] = true;
    for(int i = N - 1; i >= 0; i--)
        if(A[i] + 1 + i <= N)
            if(DP[A[i] + 1 + i]){
                sol.push_back(i);
                DP[i] = true;
            }
    sort(sol.begin(), sol.end());
    for(int i = 0; i < sol.size(); i++)
        cout << sol[i] << "\n";


    return 0;
}
