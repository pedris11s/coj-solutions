#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    double a, b, d;

    for(int i = 0; i < t; i++)
    {
        scanf("%lf%lf%lf", &a, &b, &d);
        double time = d / (a + b);
        printf("%.4lf\n", time);
    }
    return 0;
}
