#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double d, D;
    while(cin >> d >> D)
    {
        double r = d /= 2;
        double R = D /= 2;

        double x = sqrt(2) * R - R - sqrt(2) * r + r;
        if(2 * r <= x)
        {
            printf("%.8lf\n", (2 * R) * (2 * R));
            continue;
        }

        double p = sqrt((r + R) * (r + R) - (r - R) * (r - R));

        double a = 2 * R;
        double b = R + r + p;
        double area = a * b;
        printf("%.8lf\n", area);
    }
    return 0;
}
