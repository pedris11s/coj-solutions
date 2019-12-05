#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        double a, b;
        scanf("%lf%lf", &a, &b);
        double sol = a / b;
        printf("%.2lf\n", sol);
    }

    return 0;
}
