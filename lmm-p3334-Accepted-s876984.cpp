#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    string S, P;
    cin >> N >> S >> L >> P;

    int j = 0, cont = 0;
    for(int i = 0; i < N; i++)
    {
        if(S[i] == P[j])
        {
            j++;
            if(j == L)
            {
                j = 0;
                cont++;
            }
        }
    }
    int sol = N - (L * cont);
    if(sol == N)
        sol = -1;
    cout << sol << "\n";


    return 0;
}
