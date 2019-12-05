#include <cstdio>
#include <algorithm>

using namespace std;

int max2 = 0;

int seq(int n)
{
    if(n == 1) return 1;
    if(n & 1) return max(n,seq(3 * n + 1));
    else return max(n,seq( n / 2));
}

int main()
{
    int n;
    double sol;
    while(true)
    {
        scanf("%d",&n);
        if(n == 0)
           break;
        else
           printf("%d\n",seq(n));
    }
    return 0;
}
