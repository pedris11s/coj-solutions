#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    //n & (n + 1)
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long n;
        scanf("%lld", &n);
        if(n == 0)
            printf("NO\n");
        else if((n & (n + 1)) == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
