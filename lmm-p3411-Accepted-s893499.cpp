#include <bits/stdc++.h>

using namespace std;

const double PI = acos(0) * 2.0;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        double r;
        scanf("%lf", &r);
        double sol = (PI * r * r) - (2 * r * 2 * r / 2);
        printf("%.2lf\n", sol);
    }
    return 0;
}
