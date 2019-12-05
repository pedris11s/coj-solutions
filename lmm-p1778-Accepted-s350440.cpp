#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        double a, b;
        scanf("%lf%lf", &a, &b);

        double sol = (3 * a * b) / 16;
        printf("%.8lf\n", sol);
    }


    return 0;
}
