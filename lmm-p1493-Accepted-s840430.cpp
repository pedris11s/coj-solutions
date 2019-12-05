#include <bits/stdc++.h>

using namespace std;

int main()
{
    double r,b,h,x,y;
    string cad;
    cin>>cad;
    if(cad=="circle")
    {
        scanf("%lf", &r);
        printf("%.2lf",(r*r)*3.14);
    }
    else if(cad=="triangle")
    {
        scanf("%lf%lf", &b, &h);
        printf("%.2lf",(b*h)/2);
    }
    else
    {
        scanf("%lf%lf", &x, &y);
        printf("%.2lf",(x*y)/2);
    }
    return 0;
}
