#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int A[MAXN], TA[MAXN];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    for(int i = 1; i <= N; i++)
        TA[i] = TA[i - 1] + A[i];

    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", TA[b] - TA[a - 1]);
    }



    return 0;
}
