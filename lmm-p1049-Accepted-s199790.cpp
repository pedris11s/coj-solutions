#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    bool negative = n < 0;
    n = abs(n);   
   
    int sol = n & 1 ? ((n + 1) >> 1) * n : (n >> 1) * (n + 1);
   
    if (negative)
       sol = -sol + 1;
    printf("%d\n", sol);
}