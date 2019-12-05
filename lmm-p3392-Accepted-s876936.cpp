#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(true)
    {
        int n;
        scanf("%d", &n);
        if(n == 0)
            break;
        if(n == 1)
            printf("0\n");
        else
            printf("%d\n", 12 * (n - 2));
    }

    return 0;
}
