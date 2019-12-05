#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int k = 1;
    while(t--)
    {
        int n, ni;
        scanf("%d%d", &n, &ni);
        double sol = (double)n * n / (1 << ni - 1);
        sol += 0.000005;
        printf("Case #%d: %.2lf\n", k++, sol);
    }


    return 0;
}
