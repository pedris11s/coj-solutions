#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int N, A[MAXN];

int sol()
{
    int x = 0;
    for(int i = 1; i <= N; i++)
    {
        x = max(abs(A[i] - i), x);
    }
    return x;
}

int main()
{
    int t;
scanf("%d", &t);
    while(t--)
    {
scanf("%d", &N);
        for(int i = 1; i <= N; i++)
scanf("%d", &A[i]);

       printf("%d\n", sol());
    }


    return 0;
}
