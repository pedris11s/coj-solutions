#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define pi acos(-1)

double to_rad(double a)
{
    return pi * (a / 180);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        double a, b;
        scanf("%lf%lf", &a, &b);

        double sum = 0.0;
        while(b > 0.000000001)
        {
            double x = (b * sin(to_rad(60))) / sin(to_rad(120) - to_rad(a));
            sum += x;
            double y = (x * sin(to_rad(a))) / sin(to_rad(60));
            b -= y;
        }
        printf("%.4lf\n", sum);
    }

    return 0;
}

