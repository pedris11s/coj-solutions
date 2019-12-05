#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    int sol = 0;
    for(int i = 1; i <= N; i++)
    {
        int sum = 0, j = i;

/*
5 6
1 10 10 10 5

*/
        bool flag = false;
        while(sum <= M && j <= N){
            sum += A[j];
            j++;
            if(i == N && j == N + 1 && !flag)
            {
                j = 1;
                flag = true;
            }
        }

        if(j == 1 && i == N)
            sum -= A[N];
        else
            sum -= A[j - 1];

        sol = max(sol, sum);
    }
    cout << sol << "\n";

    return 0;
}
