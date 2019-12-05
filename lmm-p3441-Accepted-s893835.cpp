#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", i, (int)log2(n));
    }
    return 0;
}
