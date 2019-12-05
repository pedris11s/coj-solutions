#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 7;

int N, Q;
int A[MAXN], F[MAXN][10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> N){
        for(int i = 1; i <= N; i++)
            for(int j = 0; j < 10; j++)
                F[i][j] = 0;

        for(int i = 1; i <= N; i++){
            cin >> A[i];
            F[i][A[i]]++;
        }

        for(int j = 0; j < 10; j++)
            for(int i = 1; i <= N; i++)
                F[i][j] += F[i - 1][j];

       // for(int i = 0; i < 10; i++)
       //     cout << F[N][i] << endl;

        cin >> Q;
        while(Q--)
        {
            int a, b;
            cin >> a >> b;

            int sol = 0;
            for(int i = 0; i < 10; i++)
            {
                int freq = F[b][i] - F[a - 1][i];
                if(freq > 0)
                    sol++;
            }
            cout << sol << "\n";
        }
    }


    return 0;
}
