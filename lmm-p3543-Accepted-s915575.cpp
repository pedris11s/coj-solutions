#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

typedef long long LL;

int N, A[MAXN];

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    int sol = (1000000000);
    for(int i = 1; i <= N; i++)
    {
        int j = (i + 1) % N;
        if(j == 0)j = N;
        int cont = 1, sum = 0;
        while(i != j)
        {
            sum += A[j] * cont;
            cont++;
            j = (j + 1) % N;
            if(j == 0)j = N;
        }
        if(sum < sol)sol = sum;
    }
    cout << sol << "\n";

    return 0;
}
