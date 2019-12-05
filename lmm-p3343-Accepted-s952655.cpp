#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int cases;
        cin >> cases;
        double d, a, b, f;
        scanf("%lf %lf %lf %lf", &d, &a, &b, &f);
        //cin >> cases >> d >> a >> b >> f;

        double t = d / (a + b);
        double sol = f * t;
        printf("%d %1.2f\n", cases, sol);
    }

    return 0;
}
