#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int xL, yL, xR, yR;
    while(scanf("%d%d%d%d", &xL, &yL, &xR, &yR) != EOF){
        double sol = ((xR - xL) * (xR - xL) + (yR - yL) * (yR - yL)) / 6.0;
        printf("%.5lf\n", sol);
    }


    return 0;
}
