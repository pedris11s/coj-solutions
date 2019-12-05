#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const double pi = 3.14159265359;

double req(double L)
{
    return L * sin(60) / 3;
}

double r(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    return area / p;
}

double volumen(double r)
{
    return pi * r * r;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    double r1 = r(a, a, a);
    double r2 = r(b, b, b);
    double r3 = r(c, c, c);
    double r4 = r(a, b, c);

    double sol = volumen(r1) + volumen(r2) + volumen(r3) + volumen(r4);
    printf("%.3lf\n", sol);


    return 0;
}


