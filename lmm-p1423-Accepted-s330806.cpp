#include <cstdio>
#include <cmath>

int main()
{
    double l;

    while(scanf("%lf", &l) != EOF)
    {
        double sol = (l * sqrt(3)) / 4;
        printf("%.6lf\n", sol);
    }
    return 0;
}
